#include <string>
#include <set>
using std::string;
using std::set;

// 类声明
class Message;
class Folder;

// 类定义
class Message
{
public:
    Message(const string& msg = ""):content(msg) {}
    Message(const Message& msg);
    Message& operator=(const Message& msg);
    ~Message();

    void save(Folder& folder);
    void remove(Folder& folder);
private:
    string content;
    set<Folder*> folders;

    void put_msg_in_folders(const set<Folder*>& folders);
    void remove_msg_from_folders();
    void add_folder(Folder* folder_ptr);
    void rem_folder(Folder* folder_ptr);
};

class Folder
{
public:
    Folder(const Folder& folder):messages(folder.messages) { }
    Folder& operator=(const Folder& folder);
    ~Folder();

    void add_msg(Message* msg_ptr);
    void rem_msg(Message* msg_ptr);

private:
    set<Message*> messages;

    void put_folder_in_msgs(const set<Message*>&);
    void rem_folder_from_msgs();
};

// 注意复制构造和=号的区别!
Message::Message(const Message &msg):
    content(msg.content), folders(msg.folders)
{
    put_msg_in_folders(folders);
}

Message& Message::operator=(const Message& msg)
{
    if(&msg != this)
    {
        remove_msg_from_folders();
        content = msg.content;
        folders = msg.folders;
        put_msg_in_folders(msg.folders);
    }

    return *this;
}

Message::~Message()
{
    remove_msg_from_folders();
}

void Message::put_msg_in_folders(const set<Folder*>& folders)
{
    set<Folder*>::const_iterator itr;
    for(itr = folders.begin(); itr != folders.end(); ++itr)
        (*itr)->add_msg(this);
}

void Message::remove_msg_from_folders()
{
    set<Folder*>::const_iterator itr;
    for(itr = folders.begin(); itr != folders.end(); ++itr)
        (*itr)->rem_msg(this);
}

void Message::add_folder(Folder* folder_ptr)
{
    folders.insert(folder_ptr);
}

void Message::rem_folder(Folder* folder_ptr)
{
    folders.erase(folder_ptr);
}

void Message::save(Folder& folder)
{
    add_folder(&folder);
    folder.add_msg(this);
}

void Message::remove(Folder& folder)
{
    rem_folder(&folder);
    folder.rem_msg(this);
}


Folder& Folder::operator=(const Folder& folder)
{
    if(&folder != this)
    {
        rem_folder_from_msgs();
        messages = folder.messages;
        put_folder_in_msgs(folder.messages);
    }

    return *this;
}

void Folder::add_msg(Message* msg_ptr)
{
    messages.insert(msg_ptr);
}

void Folder::rem_msg(Message* msg_ptr)
{
    messages.erase(msg_ptr);
}

void Folder::put_folder_in_msgs(const set<Message*>& messages)
{
    set<Message*>::const_iterator itr;
    for(itr = messages.begin(); itr != messages.end(); ++itr)
        (*itr)->save(*this);
}

void Folder::rem_folder_from_msgs()
{
    set<Message*>::const_iterator itr;
    for(itr = messages.begin(); itr != messages.end(); ++itr)
        (*itr)->remove(*this);
}

