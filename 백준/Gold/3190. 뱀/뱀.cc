#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<pair<int,int>> apples;
deque<pair<int,int>> snake;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);


    for(int i=0;i<k;i++) {
        pair<int,int> in;
        scanf("%d %d", &in.second, &in.first);
        apples.push_back(in);
    }

    int l;
    scanf("%d", &l);

    vector<pair<int,char>> moves(l);
    for(int i=0;i<l;i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        moves[i]={x,c};
    }

    int t=0;
    int dir=0;

    snake.push_front({1,1});


    int moved=0;

    while(1) {
        if(t==moves[moved].first) {
            //printf("turned");
            if(moves[moved].second=='D') {
                dir=(dir+1)%4;
            }
            else if(moves[moved].second=='L') {
                dir=(dir+3)%4;
            }
            moved++;
        }


        t++;
        int newx = snake.front().first+dx[dir];
        int newy=snake.front().second+dy[dir];
        if(newx<=0 || newy<=0||newx>n || newy>n) {
            break;
        }

        for(pair<int,int> a:snake) {
            if(a.first==newx&& a.second==newy) {
                goto e;
            }
        }

        snake.push_front({newx,newy});

        int eat=0;

        for(auto &apple:apples) {
            if(apple.first==newx&&apple.second==newy) {
                apple.first=apple.second=0;
                eat=1;
                break;
            }
        }

        if(!eat) {
            snake.pop_back();
        }
        /*printf("%d\n",t);
        for(int i=1; i<=n;i++) {             // Board starts from (1,1)
            for(int j=1; j<=n;j++) {
                int check_snake=0;
                for(pair<int,int> a:snake) {
                    if(a.first==j && a.second==i) {
                        check_snake=1;
                        break;
                    }
                }

                int check_apple=0;
                for(pair<int,int> a:apples) {
                    if(a.first==j && a.second==i) {
                        check_apple=1;
                        break;
                    }
                }

                if(check_snake) {
                    printf("D");
                }
                else if(check_apple) {
                    printf("A");
                }
                else {
                    printf("/");
                }
            }
            printf("\n");
        }
        printf("\n");*/
    }

e:
    printf("%d", t);

    return 0;
}
