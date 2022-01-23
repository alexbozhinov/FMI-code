#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

const int MAX_LENGTH = 100;

class User{

public:
    User();
    User(const char*, const char*);

    void setUsername(const char* );
    void setPassword(const char* );

    void printClient()const;

private:
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    void setAllU(const char*, const char*);

};


#endif // USER_H_INCLUDED
