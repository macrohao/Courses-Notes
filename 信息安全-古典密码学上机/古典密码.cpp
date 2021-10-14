#include<iostream>
#include<algorithm>
#include<string>
#define maxlen 21
using namespace std; 


string before;
int len_before;
string after;
int len_after;

string password;
int f_password[maxlen] = {0};
int len_password = 0;
bool hashtable[26] = {false}; 

void menu();
void setpassword();
void input();
void change();



int main(){
	
	menu();
	
	return 0;
}

void menu(){
    printf("-------- --����ָ����в���---------\n");
    printf("             1-������Կ             \n");
    printf("             2-��������             \n");
    printf("             3-��������             \n");
    printf("             4-��������             \n");
    printf("             0-�˳�ϵͳ             \n");
    printf("------------------------------------\n");
    int choice;
    cin >> choice;
    while(choice != 0){
    	switch(choice){
    		case 1:
    			setpassword();
    			break;
    		case 2:
    			input();
    			break;
    		case 3:
    			change();
    			break;
    		case 4:
				change();
				break;
			default:
				printf("�Ƿ�ָ����������룡\n");
		}
		cin >> choice;
	}
}


void setpassword(){
	printf("��������Կ�ַ�����\n");
	cin >> password;
	len_password = password.length();
	
	int temp;
	for(int i = 0; i < len_password; i++){
		temp = password[i] - 'a';
		hashtable[temp] = true;
	}
	
	for(int i = 0; i < len_password; i++){
		int cnt = 0;
		for(int j = 0; j <= (password[i] - 'a'); j++){
			if(hashtable[j] == true) cnt++;
		}
		
		f_password[i] = cnt;
	}

	
	printf("��ǰ��Կ�û�����Ϊ��\n");
	for(int i = 0; i < len_password; i++ ){
		printf("%d ",i + 1);
	}
	printf("\n");
	for(int i = 0; i < len_password; i++ ){
		printf("%d ",f_password[i]);
	}
}

void input(){
	printf("���������ģ�\n");
	cin>>before;
	len_before = before.length();
	printf("��ǰ����Ϊ��\n");
	for(int i = 0; i < len_before; i++){
		printf("%c",before[i]);
		if(i>1 && i%len_password == len_password - 1){
			printf("\n");
		}
	} 
}

void change(){
	after = before;
	len_after = after.length();
	if(len_after % len_password != 0){
		printf("��ǰ��Կ���������ĳ��Ȳ�ƥ�䣬�޷����м��ܣ�\n");
	}else{
		for(int i = 0; i < after.length(); i++){
			after[i] = before[i / len_password * len_password + f_password[i%len_password] - 1];
			//swap(after[i],after[f_password[i] - 1]);
			
		}
	}
	
	printf("���ܺ�����//���ܺ����ģ�\n");
	for(int i = 0; i < len_after; i++){
		printf("%c",after[i]);
		if(i>1 && i%len_password == len_password - 1){
			printf("\n");
		}
	} 
}

