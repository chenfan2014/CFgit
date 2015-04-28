class Message{          //电子邮件消息
    public:
        Message(const std::string &str = "")            //可以隐式由string转化成Message对象。
            :contents(str)
        {}
        virtual ~Message();

        Message(const Message &m)   
            :contents(m.contents), folders(m.folders)
        {
            putMsgInFolders(folders);
        }
        Message operator = (const Message &);
        
        void Save(Folder &);
        void Remove(Folder &);
    private:
        std::string contents;               //保存实际消息
        std::set<Folder *> folders;         //set，包含指向该Message所在的Folder指针

        void putMsgInFolders(const std::set<Folder *> &rhs)
        {
            for(std::set<Folder *>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg){
                (*beg) -> addMsg(this);
            }
        }
        void removeMsgFromFolders();
};

class Folder{           //电子邮件消息所出现目录
    public:
        Folder();
        virtual ~Folder();
    private:
        
};



class SalesItem{
    private:
        friend std::ostream& operator << (std::ostream &os, const SalesItem & si);
        friend std::istream& operator >> (std::istream &is, const SalesItem &si);
    public:
        SalesItem &operator += (const SalesItem &si);
};
SalesItem& operator +(const SalesItem &siOne, const SalesItem &siTwo)
{
    SalesItem s(siOne);
    s += siTwo;
    return s;
}

