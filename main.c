#include <stdio.h>
#include <stdlib.h>

int session=-1;

struct node{
	int nim;
	char nama[100];
	char kelamin[10];
	char tgl_lahir[100];
	char tempat_lahir[100];
	char alamat[100];
	char kelas;
	float UAS, UTS, quiz, tgs, rata;
	char grade;

	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void login();
void header();
void DataMahasiswa();
void NilaiMahasiswa();
void Kelulusan();
void dataMhs(int);
void editDataDiri(int);
void cekLulus(int);

int main(){

	if(session==-1){
		login();
	}

	int pil;
	char rep;

	do{
	system("cls");
	header();
	puts("|                      MAIN MENU                         |");
	puts("==========================================================");
	puts(" --> 1. Data Pokok");
	puts(" --> 2. Nilai");
	puts(" --> 3. Kelulusan");
	puts(" --> 4. Log Out");
	puts(" --> 5. Exit");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d",&pil);

	switch(pil){
		case 1 :
			DataMahasiswa();
		break;
		case 2 :
			NilaiMahasiswa();
		break;
		case 3 :
			Kelulusan();
		break;
		case 4:
            login();
            break;
        case 5:
            exit(1);
            break;
		default:
			puts(" --> Pilihan tidak tersedia");
		break;
	}

	puts("==========================================================");
	printf(" --> Kembali ke menu utama ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
	login();
}

void header(){
	puts("|========================================================|");
	puts("|          ****** PROGRAM DATA MAHASISWA ******          |");
	puts("|                 ### UNIVERSITAS X ###                  |");
	puts("|                         2021                           |");
	puts("|=========================^^^^===========================|");
}

void login(){
	int cek;
	char user[100], pass[100];
	char data[]="admin";

	system("cls");

	header();


	puts("|            SILAHKAN LOGIN TERLEBIH DAHULU              |");
	puts("==========================================================");
	puts("");
	printf("     --> Masukan Username : ");
	fflush(stdin);
	gets(user);

	printf("     --> Masukan Password : ");
	fflush(stdin);
	gets(pass);



	int cekuser=strcmp(user,data);
	int cekpass=strcmp(pass,data);

	if(cekuser==0 && cekpass==0) {
		puts("");
		puts("     --> Login Berhasil!");
		getch();
		session=1;
		main();
	}

	struct node *bantu;
	int cekLog;
	char keep[100];

	bantu=head;
	cekLog=0;


	while(bantu!=NULL && cekLog==0){

		sprintf(keep, "%d", bantu->nim);

		int cekuser=strcmp(user,keep);
		int cekpass=strcmp(pass,keep);

		if(cekuser==0 && cekpass==0){
			cekLog=1;
			break;
		}

		bantu=bantu->next;
	}

	if(cekLog==1){

		puts("");
		puts("     --> Login Berhasil!");

		getch();
		session=1;

		dataMhs(bantu->nim);

	}

	else{

		puts("");
		puts("     --> Username / Password Salah");

		getch();

		login();
	}

}

void DataMahasiswa(){
	int pil;
	char rep;
	do{
	system("cls");
	header();
	puts("|                DATA INDUK MAHASISWA                    |");
	puts("==========================================================");
	puts(" --> 1. Tampilkan Data");
	puts(" --> 2. Tambah Data");
	puts(" --> 3. Hapus Data");
	puts(" --> 4. Edit Data");
	puts(" --> 5. Kembali");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d",&pil);

	switch(pil){
		case 1 :
			showMahasiswa();
		break;
		case 2 :
			addMahasiswa();
		break;
		case 3 :
			deleteMahasiswa();
		break;
		case 4 :
			editMahasiswa();
		break;
		case 5 :
			main();
		break;
		default:
			puts(" --> Pilihan tidak tersedia");
		break;
	}

	puts("==========================================================");
	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
}
