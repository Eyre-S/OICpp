#define t


#ifdef t

    #include <iostream>

    using namespace std;
    // 本地词典
    int lib[1000] = {0};
    // 已占用内存
    int memorize = 0;
    // 总内存
    int RAM = 0;
    // 请求数
    int question = 0;
    // 查阅词典数
    int checkout = 0;
    
    int main()
    {
        
        cin >> RAM >> question;
        // 内存数据
        int memList[question];
        // 首尾位置
        int tail = 0;
        int head = 0;

        for (register int i = 0; i < question; ++i) {
            register int word;
            cin >> word;
            if (lib[word] != 1) {
                memList[head] = word;
                head++;
                if (memorize == RAM) {
                    memorize--;
                    lib[memList[tail]] = 0;
                    tail++;
                }
                lib[word] = 1;
                memorize++;
                checkout++;
            }
        }

        cout << checkout;

        return 0;
    }

#endif