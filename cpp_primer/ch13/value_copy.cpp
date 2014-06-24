class HasPtr
{
public:
    HasPtr(const int &p, int i):ptr(new int(p)), val(i) { }
    HasPtr(const HasPtr &orig):
        ptr(new int(*orig.ptr)), val(orig.val) { }
    HasPtr& operator=(const HasPtr &orig)
    {
        *ptr = *orig.ptr;
        val = orig.val;
        return *this;
    }
    ~HasPtr(){ delete ptr; }

    int *get_ptr() const { return ptr; }
    int get_val() const { return val; }
    
    void set_ptr(int *p) { ptr = p; }
    void set_val(int i) { val = i; }

    int get_ptr_val() const { return *ptr; }
    void set_ptr_val(int i) const { *ptr = i; }

private:
    int *ptr;
    int val;
};
