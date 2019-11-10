#define SUKAYO

#ifdef SUKAYO

    #include <iostream>

    using namespace std;

    int m_space;
    int road[8][2] = {{1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,1},{-1,-1},{-1,0}};
    int veryi[6] = {105, 122, 104, 111, 110, 103};

    int main()
    {
        cin >> m_space;

        int matrix[m_space][m_space];
        register int able[m_space][m_space];

        // 输入
        for (register int i = 0; i < m_space; ++i) {
            for (register int j = 0; j < m_space; ++j) {
                char tmp;
                cin >> tmp;
                matrix[i][j] = tmp;
                able[i][j] = 0;
            }
        }

        for (register int i = 0; i < m_space; ++i) {
            for (register int j = 0; j < m_space; ++j) {
                if (matrix[i][j] == 121) {
                    // 八个方向
                    for (register int r = 0; r < 8; ++r) {
                        register bool ok = true;
                        // 检查ok
                        for (register int m = 1; m <= 6 && ok == true; ++m) {
                            if (i+(road[r][0]*m) > -1 && j+(road[r][1]*m) > -1 && i+(road[r][0]*m) < m_space && j+(road[r][1]*m) < m_space) {
                                if (matrix[i+(road[r][0]*m)][j+(road[r][1]*m)] != veryi[m-1]) {
                                    ok = false;
                                }
                            } else {
                                ok = false;
                            }
                        }

                        // 输出ok
                        if (ok == true) {
                            for (register int m = 0; m <= 6; ++m) {
                                able[i+(road[r][0]*m)][j+(road[r][1]*m)] = 1;
                            }
                        }
                    }
                }
            }
        }

        // 输出
        for (register int i = 0; i < m_space; ++i) {
            for (register int j = 0; j < m_space; ++j) {
                if (able[i][j] == 0) {
                    cout << '*';
                } else {
                    cout << char(matrix[i][j]);
                }
            }
            cout << endl;
        }

        // for (int i = 0; i < 8; ++i) {
        // 	for (int m = 1; m <= 6; ++m) {
        // 		cout << road[i][0]*m << "|" << road[i][1]*m << "  ";
        // 	}
        // 	cout << endl;
        // }

        return 0;
    }
#endif