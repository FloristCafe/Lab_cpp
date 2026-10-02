#include<iostream>
#include<cstdio>
#include<cstring>
struct Contact {
    char name[30];
    char phone[30];
    char className[30];
    int dorm;
};

class SeqList {
private:
    Contact data[20005]; 
    int length;

public:
    SeqList() {
        length = 0;
    }

    void insert(char* name, char* phone, char* className, int dorm) {
        strcpy(data[length].name, name);
        strcpy(data[length].phone, phone);
        strcpy(data[length].className, className);
        data[length].dorm = dorm;
        length++;
    }

    void remove(const char* name) {
        int idx = -1;
        for (int i = 0; i < length; i++) {
            if (strcmp(data[i].name, name) == 0) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return; 
        
        for (int i = idx; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    int find(const char* name) {
        for (int i = 0; i < length; i++) {
            if (strcmp(data[i].name, name) == 0) {
                return i;
            }
        }
        return -1;
    }

    void edit(const char* name, int item, const char* newval) {
        int idx = find(name);
        if (idx == -1) return;
        
        if (item == 1) {
            strcpy(data[idx].phone, newval);
        } else if (item == 2) {
            strcpy(data[idx].className, newval);
        } else if (item == 3) {
            data[idx].dorm = atoi(newval); 
        }
    }

    int queryor(const char* className) {
        int value = 0;
        for (int i = 0; i < length; i++) {
            if (strcmp(data[i].className, className) == 0) {
                value ^= data[i].dorm;
            }
        }
        return value;
    }
};
using namespace std;

int main() {
    int n;
   cin>>n;

    SeqList list;

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 0) {
            char name[30], phone[30], className[30];
            int dorm;
            scanf("%s %s %s %d", name, phone, className, &dorm);
            list.insert(name, phone, className, dorm);
        } 
        if (op == 1) {
            char name[30];
            scanf("%s", name);
            list.remove(name);
        } 
       if (op == 2) {

            char name[30], newValue[30];
            int item;
            scanf("%s %d %s", name, &item, newValue);
            list.edit(name, item, newValue);
        } 
  if (op == 3) {
           
            char name[30];
            scanf("%s", name);
            int idx = list.find(name);
            if (idx != -1) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } 
        if (op == 4) {

            char className[30];
            scanf("%s", className);
            printf("%d\n", list.queryor(className));
        }
    }

    return 0;
}