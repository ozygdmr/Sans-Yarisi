#include <iostream>
#include<cstdlib>
#include<stdlib.h>
#include<thread>
#include <chrono>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int oyunbitti = 0,birincx = 1,birincy = 1,i,j = 0,ikincx = 1,ikincy = 3,oyuncu,jeton = 0,bahis = 0;
	
	char game[5][100];
	
	y:
	cout<<"Baslangic Jetonunu Gir(1 ile 1000 arasi):";
	cin>>jeton;
	if(jeton > 0 && jeton <= 1000){
		
	}else{
		goto y;
	}
	x:
	cout<<"Hangi Oyuncusun(1 ya da 2):";
	cin>>oyuncu;
    if(oyuncu == 1 || oyuncu == 2){
    	cout<<oyuncu<<". oyuncuyu sectin"<<endl;
	}else{
		cout<<"yanlis girdi var tekrar dene";
		goto x;
	}
	
		
	for(i = 0;i<100;i++){
		game[0][i] = '#';
		game[4][i] = '#';
	}
	for(i=0;i<5;i++){
		game[i][0] = '#';
		game[i][99]=  '#';
	}
	j=2;
	for(i=0;i<100;i++){
		game[j][i] = '-';
	}
	b:
	cout<<"Jeton:"<<jeton<<endl;
    cout<<"Bahis Gir:";
    cin>>bahis;
    if(bahis > jeton || bahis<0){
    	cout<<"Yanlis Bahis Tekrar Bahis Gir:";
    	goto b;
	}
	 birincy = 1;
	    ikincy = 3;
	    birincx = 1;
	    ikincx = 1;
	while(oyunbitti == 0){
		cout<<"Jeton:"<<jeton<<endl;
		cout<<"Bahis:"<<bahis<<endl;
		cout<<"Oyuncu:"<<oyuncu<<endl;
	   
		for(j=1;j<99;j++){
			game[1][j] = ' ';
			game[3][j] = ' ';
			}
		birincx += rand() % 10;
		ikincx += rand() % 10;
		
		
		game[birincy][birincx] = '*';
		game[ikincy][ikincx] = '*';
		
		
		
		for(i=0;i<5;i++){
			for(j=0;j<100;j++){
				cout<<game[i][j];
			}
			cout<<endl;
		}
	    
        this_thread::sleep_for(200ms);
		system("CLS");
		if(birincx >= 99 && oyuncu == 1 ){
			cout<<"Oyunu Kazandin"<<endl;
			jeton += bahis;
			goto b;
		}else if(ikincx >= 99&&oyuncu == 2){
			cout<<"Oyunu Kazandin"<<endl;
			jeton += bahis;
			goto b;
		}else if(birincx >=99 && oyuncu == 2){
			cout<<"Oyunu Kaybettin"<<endl;
			jeton -= bahis;
			if(jeton > 0){
				goto b;
			}else{
				oyunbitti = 1;
			}
			
		}else if(ikincx >=99 && oyuncu == 1){
			cout<<"Oyunu Kaybettin"<<endl;
			
			jeton -= bahis;
			if(jeton > 0){
				goto b;
			}else{
				oyunbitti = 1;
			}
		}else if(birincx >= 99 && ikincx >=99){
			cout<<"Oyun Berabere Tekrar Dene"<<endl;
			goto b;
		}
	}
	return oyunbitti;
}