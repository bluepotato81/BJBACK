#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct {
    string name;
    int region;
    int votes;
    int eli;
    double voteper;
    int linkseatraw;
    int linkseat;
}party;

bool comp(const party& a, const party& b) {
    if(a.region+a.linkseat==b.region+b.linkseat) {
        return a.name<b.name;
    }
    else {
        return a.region+a.linkseat>b.region+b.linkseat;
    }
}




int main() {
    vector<party> parties;
    vector<party>::iterator index;

    int p,v;
    scanf("%d %d", &p, &v);

    parties.resize(p);

    int stot=0;

    for(int i=0;i<p;i++) {
       cin >> parties[i].name >> parties[i].region >> parties[i].votes;


    }

    int totvotes=0;
    for(index=parties.begin(); index!=parties.end();++index) {
        totvotes+=index->votes;
    }

    for(index=parties.begin();index!=parties.end();++index) {
        if(index->votes/(double)totvotes>=0.03) {
            index->eli=1;
        }
        if(index->region>=5) {
            index->eli=1;
        }
    }

    int numlink=47;
    int elivotes=0;

    for(index=parties.begin();index!=parties.end();++index) {
        if(index->eli) {
            numlink+=index->region;
            elivotes+=index->votes;
        }
    }

    int totlink=0;

    for(index=parties.begin();index!=parties.end();++index) {
        if(index->eli) {
            double check;
            index->voteper=(double)index->votes/elivotes;
            check=(numlink*index->voteper - index->region)/2.0;
            index->linkseatraw=(check<1.0) ? 0 : (int)round(check);
            totlink+=index->linkseatraw;
        }
    }
    if(totlink==30) {
        for(index=parties.begin();index!=parties.end();++index) {
            if(index->eli) {
                index->linkseat=index->linkseatraw;
            }
        }
    }

    else if(totlink<30) {
        int rem=30-totlink;
        totlink=0;
        multimap<double, int, greater<double>> bef;
        multimap<double, int, greater<double>>::iterator befindex;

        for(index=parties.begin();index!=parties.end();++index) {
            if(index->eli) {
                double moreseat=rem*index->voteper;
                double fr=moreseat-(int)moreseat;
                index->linkseat = index->linkseatraw+(int)moreseat;
                totlink+=index->linkseat;
                bef.insert(make_pair(fr,index-parties.begin()));
            }
        }

        for(befindex=bef.begin();befindex!=bef.end();++befindex) {
            if(totlink==30) {
                break;
            }
            ++parties[befindex->second].linkseat;
            ++totlink;
        }


    }

    else {
        double ov = 30.0/totlink;
        totlink=0;
        multimap<double, int, greater<double>> bef;
        multimap<double, int, greater<double>>::iterator befindex;

        for(index=parties.begin();index!=parties.end();++index) {
            if(index->eli) {
                double lessseat=ov*index->linkseatraw;
                double fr=lessseat-(int)lessseat;
                index->linkseat =(int)lessseat;
                totlink+=index->linkseat;
                bef.insert(make_pair(fr,index-parties.begin()));
            }
        }

        for(befindex=bef.begin();befindex!=bef.end();++befindex) {
            if(totlink==30) {
                break;
            }
            parties[befindex->second].linkseat++;
            totlink++;
        }
    }



    int totseat=0;
    multimap<double, int, greater<double>> bef;
    multimap<double, int, greater<double>>::iterator befindex;

    for(index=parties.begin();index!=parties.end();++index) {
        if(index->eli) {
            double seat=17 * index->voteper;
            double fr=seat-(int)seat;
            index->linkseat += (int)seat;
            totseat+=(int)seat;
            bef.insert(make_pair(fr,index-parties.begin()));
        }
    }

    for(befindex=bef.begin();befindex!=bef.end();++befindex) {
        if(totseat==17) {
            break;
        }
        parties[befindex->second].linkseat++;
        totseat++;
    }

    sort(parties.begin(), parties.end(), comp);

    for(index=parties.begin();index!=parties.end();++index) {
        cout << index->name << " " << index->region + index->linkseat << '\n';
    }


    return 0;

}


