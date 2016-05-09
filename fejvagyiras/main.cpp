#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

//
// F=1; I=0
//

void t1(){
    int random=rand()%2;
    cout<<"A penzfeldobas eredmenye: ";
    if(random==1){
        cout<<"F"<<endl;
    }else{
        cout<<"I"<<endl;
    }
}
void t2(){
    char userInput;
    cout<<"Tippeljen! (F/I)= ";
    cin>>userInput;

    int random=rand()%2;
    char randomRes;
    if(random==1){
        randomRes='F';
    }else{
        randomRes='I';
    }

    cout<<"A tipp "<<userInput<<", a dobas eredmenye "<<randomRes<<" volt."<<endl;

    if(randomRes==userInput){
        cout<<"On eltalalta!"<<endl;
    }else{
        cout<<"On nem talalta el."<<endl;
    }
}

int main(){
    srand(time(NULL)); // Init randm

    cout<<"1. Feladat"<<endl;
    t1();
    cout<<endl;
    cout<<"2. Feladat"<<endl;
    //t2();
    cout<<endl;
    cout<<"3. Feladat"<<endl;

    int lineNum=0;
    float all=0.0;
    float fejSum=0.0;

    ifstream fileCounter("kiserlet.txt");
    if(fileCounter.is_open()){
        string line="";
        while(getline(fileCounter, line)){
            lineNum++;
            all++;
            if(line=="F"){
                fejSum++;
            }
        }
    }
    fileCounter.close();
    cout<<"A kiserlet "<<lineNum<<" dobasbol allt."<<endl;

    cout<<endl;
    cout<<"4. Feladat"<<endl;


    float res=(round((fejSum/all)*10000))/100;
    cout<<"A kiserlet soran a fej relativ gyakorisaga "<<res<<"% volt."<<endl;

    cout<<endl;
    cout<<"5. Feladat"<<endl;

    int fCounter=0;
    ifstream fileInput("kiserlet.txt");
    if(fileInput.is_open()){
        string line[3];
        string lastFromPrev="";
        for(int i=0;i<lineNum;i++){
            getline(fileInput,line[0]);
            getline(fileInput,line[1]);
            getline(fileInput,line[2]);

            if(lastFromPrev!="F"){
                if(line[0]=="F"&&line[1]=="F"&&line[2]!="F"){
                    fCounter++;
                }
            }else if(lastFromPrev=="F"&&line[0]=="F"&&line[1]!="F"){
                fCounter++;
            }
            lastFromPrev=line[2];
        }
    }
    fileInput.close();
    cout<<fCounter<<endl;

    cout<<endl;
    cout<<"6. Feladat"<<endl;

    ifstream fileInp("kiserlet.txt");
    int index=0;
    int counter=0;
    if(fileInp.is_open()){
        int lineCount=0;
        while(!fileInp.eof()){
            string line="";
            string line2="";
            string line3="";

            getline(fileInp,line);
            getline(fileInp,line2);
            getline(fileInp,line2);
            lineCount++;
            if(line=="F"&&line2=="F"&&line3=="F"){
                counter++;
                index=lineCount;
            }else{
                counter=0;
            }
        }
    }

    cout<<counter<<" "<<index<<endl;

    cout<<endl;
    cout<<"7. Feladat"<<endl;

    ofstream fileOutput("dobasok.txt");

    char dobasok[1000][4];

    for(int i=0;i<1000;i++){
        int randoms[4];
        randoms[0]=rand()%2;
        randoms[1]=rand()%2;
        randoms[2]=rand()%2;
        randoms[3]=rand()%2;

        char randomRess[4];
        for(int c=0;c<4;c++){
            if(randoms[c]==1){
                randomRess[c]='F';
            }else{
                randomRess[c]='I';
            }
        }

        dobasok[i][0]=randomRess[0];
        dobasok[i][1]=randomRess[1];
        dobasok[i][2]=randomRess[2];
        dobasok[i][3]=randomRess[3];
    }
    int fejCounter=0;
    int irasCounter=0;
    for(int i=0;i<1000;i++){
        if(dobasok[i][0]=='F'&&dobasok[i][1]=='F'&&dobasok[i][2]=='F'&&dobasok[i][3]!='F'){
            irasCounter++;
        }else if(dobasok[i][0]=='F'&&dobasok[i][1]=='F'&&dobasok[i][2]=='F'&&dobasok[i][3]=='F'){
            fejCounter++;
        }

    }
    fileOutput<<"FFFF: "<<fejCounter<<", FFFI: "<<irasCounter<<"\n";
    for(int i=0;i<1000;i++){
        fileOutput<<dobasok[i][0]<<dobasok[i][1]<<dobasok[i][2]<<dobasok[i][3]<<" ";
    }
    cout<<"Fajl elmentve."<<endl;
    cout<<endl;
    return 0;
}
