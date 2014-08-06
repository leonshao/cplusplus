#include "text_query.h"
#include <ostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
#include <sstream>
using std::ostream;
using std::stringstream;
using std::size_t;
using std::vector;
using std::pair;
using std::make_pair;

// ��, ������
// ============================= Query_base Start
class Query_base
{
    friend class Query_handle;

protected:
    virtual ~Query_base() { }

private:
    // text_query.h������line_no_t
    virtual set<line_no_t> eval(const TextQuery &t) const = 0;  // ���麯��Ҫ�� = 0
    virtual ostream &display(ostream &os) const = 0;
};
// ============================= Query_base End


// ���ʲ�ѯ��
// ============================= WordQuery Start
class WordQuery: public Query_base
{
    friend class Query_handle;

    WordQuery(const string &query_word): word(query_word){ }

private:
    set<line_no_t> eval(const TextQuery &t) const { return t.run_query(word); }
    ostream &display(ostream &os) const { return os << word; }
    string word;
};
// ============================= WordQuery End



// �����, �ṩ�ӿڸ�Ӧ�ó������
// ============================= Query_handle Start
class Query_handle
{
    friend Query_handle operator&(const Query_handle &, const Query_handle &);
    friend Query_handle operator|(const Query_handle &, const Query_handle &);
    friend Query_handle operator~(const Query_handle &);
public:
    Query_handle(const string &query_word): ptr(new WordQuery(query_word)), use(new size_t(1)) { }
    Query_handle(const Query_handle &orig): ptr(orig.ptr), use(orig.use) { ++*use; }
    Query_handle& operator=(const Query_handle &orig);
    ~Query_handle() { decr_use(); }

    ostream &display(ostream &os) const { return ptr->display(os); }
    set<line_no_t> eval(const TextQuery &t) const;
private:
    Query_handle(Query_base *p): ptr(p), use(new size_t(1)) { }

    Query_base *ptr;
    size_t *use;

    void decr_use() { if(--*use == 0){ delete ptr; delete use;} }
};

Query_handle& Query_handle::operator=(const Query_handle &orig)
{
    decr_use();
    ptr = orig.ptr;
    use = orig.use;
    ++*use;
    return *this;
}

// ִ�в�ѯ, ������������
set<line_no_t> Query_handle::eval(const TextQuery &t) const
{
    return ptr->eval(t);
}
// ============================= Query_handle End


// ���ز�����<<
inline ostream &operator<<(ostream &os, const Query_handle &handle)
{
    return handle.display(os);
}



// �ǲ�ѯ, ���ز������õ��ʵ������м���
// ============================= NotQuery Start
class NotQuery: public Query_base
{
    friend Query_handle operator~(const Query_handle &);

    NotQuery(const Query_handle &q):query(q) { }
private:
    set<line_no_t> eval(const TextQuery &t) const;
    ostream &display(ostream &os) const { return os << "~" << query; }

    const Query_handle query;
};

set<line_no_t> NotQuery::eval(const TextQuery &t) const
{
    set<line_no_t> has_val = query.eval(t),
                 ret_lines = t.get_all_lines();

    set<line_no_t>::iterator itr;
    for(itr = has_val.begin(); itr != has_val.end(); ++itr)
        ret_lines.erase(*itr);

    return ret_lines;
}
// ============================= NotQuery End



// ������������ѯ��, ������
// ============================= BinaryQuery Start
class BinaryQuery: public Query_base
{
    friend class Query_handle;

protected:
    BinaryQuery(const Query_handle left, const Query_handle right, string op):
        lhs(left), rhs(right), oper(op) { }
    ostream &display(ostream &os) const
    {
        return os << "(" << lhs << ")" << " " << oper << " "
                  << "(" << rhs << ")";
    }

    const Query_handle lhs, rhs;
    string oper;
};
// ============================= BinaryQuery End


// ���ѯ, �����������ʲ�ѯ�Ľ���
// ============================= AndQuery Start
class AndQuery: public BinaryQuery
{
    friend Query_handle operator&(const Query_handle &, const Query_handle &);

    AndQuery(const Query_handle &left, const Query_handle &right):
        BinaryQuery(left, right, "&") { }

    set<line_no_t> eval(const TextQuery &t) const
    {
        // �ֱ��ȡ����������ѯ�Ľ��
        set<line_no_t> right = rhs.eval(t),
                        left = lhs.eval(t);
        set<line_no_t> ret_lines;

        // ��׼���set_intersection�㷨��ȡ�������ϵĹ�����,
        // �����뵽��ret_lines�������õ�inserter��
        set_intersection(left.begin(), left.end(),
                         right.begin(), right.end(),
                         inserter(ret_lines, ret_lines.begin()));
        return ret_lines;
    }
};
// ============================= AndQuery End


// ���ѯ, �����������ʲ�ѯ�Ĳ���
// ============================= OrQuery Start
class OrQuery: public BinaryQuery
{
    friend Query_handle operator|(const Query_handle &, const Query_handle &);

    OrQuery(const Query_handle &left, const Query_handle &right):
        BinaryQuery(left, right, "|") { }

    set<line_no_t> eval(const TextQuery &t) const
    {
        // �ֱ��ȡ����������ѯ�Ľ��
        set<line_no_t> right = rhs.eval(t),
                   ret_lines = lhs.eval(t);

        // ��ȡ������ѯ����Ĳ���, ���Ҳ�ѯ�Ľ�����뵽���ѯ�Ľ��
        ret_lines.insert(right.begin(), right.end());
        return ret_lines;
    }
};
// ============================= OrQuery End





// ������������
// =============================

inline Query_handle operator&(const Query_handle &left, const Query_handle &right)
{
    return new AndQuery(left, right);
}

inline Query_handle operator|(const Query_handle &left, const Query_handle &right)
{
    return new OrQuery(left, right);
}

inline Query_handle operator~(const Query_handle &q)
{
    return new NotQuery(q);
}
// =============================


void print_query(const Query_handle& q, 
    const set<line_no_t>& word_lines, const TextQuery& oTextQuery)
{
    cout << "Executing Query for: " << q << endl;
    cout << "match occurs " << word_lines.size() << " times:" << endl;
    for(set<line_no_t>::iterator set_itr = word_lines.begin();
        set_itr != word_lines.end(); ++set_itr)
        cout << "  (line " << *set_itr << ") " << oTextQuery.text_line(*set_itr) << endl;
}

int main()
{
    string file_name = "Alice_story.txt";
    string query_word = "Alice";
    ifstream input;
    input.open(file_name.c_str());

    TextQuery oTextQuery;
    oTextQuery.read_file(input);
    // oTextQuery.dump_map();

    vector< pair<Query_handle, set<line_no_t> > > query_history; // ���в�ѯ
    set<line_no_t> word_lines;  // ÿ����ѯ��ƥ����

    // �������ʲ�ѯ
    Query_handle q1(query_word);
    word_lines = q1.eval(oTextQuery);
    query_history.push_back(make_pair(q1, word_lines));

    // �������ʽ���
    Query_handle q2 = Query_handle("fiery") & Query_handle("bird") | ~Query_handle("wind");
    word_lines = q2.eval(oTextQuery);
    query_history.push_back(make_pair(q2, word_lines));

    // �ǲ�ѯ
    Query_handle q3 = ~Query_handle("Alice");
    word_lines = q3.eval(oTextQuery);
    query_history.push_back(make_pair(q3, word_lines));

    int history_size = query_history.size();
    cout << "query_history size: " << history_size << endl;
    string cmd;
    while (cin >> cmd)
    {
        if(cmd[0] == 'h')
        {
            for(int i = 0; i < history_size; ++i)
                cout << "Query " << i + 1 << ": " << query_history[i].first << endl;
            cout << endl;
        }
        else if(cmd[0] == 'q')
            return 0;
        else
        {
            stringstream ss(cmd);
            int num;
            if(!(ss >> num))
            {
                cout << "please input h or index num!" << endl;
                cout << endl;
                continue;
            }

            if(num < 1 || num > history_size)
            {
                cout << "input num out of range, query_history size is " << history_size << endl;
                cout << endl;
                continue;
            }

            int index = num - 1;
            print_query(query_history[index].first, query_history[index].second, oTextQuery);
            cout << endl;
        }
    }

    return 0;
}
