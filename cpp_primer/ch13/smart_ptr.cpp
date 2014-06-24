class HasPtr;
class U_Ptr;

class U_Ptr
{
    friend class HasPtr;
    int *i_ptr;
    int use;

    U_Ptr(int *p):i_ptr(p), use(1){ }
    ~U_Ptr(){ delete i_ptr; }
};

class HasPtr
{
public:
    HasPtr(int *p, int v):ptr(new U_Ptr(p)), val(v){ }
    HasPtr(const HasPtr& orig):
        ptr(orig.ptr), val(orig.val){ ++ptr->use; }
    HasPtr& operator=(const HasPtr& orig);
    ~HasPtr(){ if(--ptr->use == 0)delete ptr; }

    int *get_ptr() const { return ptr->i_ptr; }
    int get_int() const { return val; }
    
    void set_ptr(int *p) const { ptr->i_ptr = p; }
    void set_int(int i) { val = i; }

    int get_ptr_val() const { return *ptr->i_ptr; }
    void set_ptr_val(int i) { *ptr->i_ptr = i; }

private:
    U_Ptr *ptr;
    int val;
};

HasPtr& HasPtr::operator=(const HasPtr& orig)
{
    if(this != &orig)
    {
        ++orig.ptr->use;
        if(--ptr->use == 0)
            delete ptr;
        ptr = orig.ptr;
        val = orig.val;
    }

    return *this;
}
