#include <iostream>

using namespace std;

struct dll
{
    string judul;
    string channel;
    int durasi;
    dll *next;
    dll *prev;
};

dll *head = NULL;
dll *curr_podcast = NULL;
dll *tail = NULL;


// void tambahDepan(string judul, string channel, int durasi);
// void tambahTengah(string judul, string channel, int durasi, int posisi);
void tambahBelakang(string judul, string channel, int durasi);
void hapusDepan();
void hapusTengah(int posisi);
void hapusBelakang();
void cariData(string judul);
void tampilDepan();
// void tampilDurasi();
// void tampilBelakang();

//1. Menambah Data otomatis Terurut
// void sortByDurasi();

// mainkan podcast pertama
void firstNode(){
    if(head==NULL){
        cout << "Playlist masih kosong\n";
    }
    else{
        cout << "Memainkan Podcast pertama : " << head->judul << endl;
    }
}

void nextNode(){
    if(curr_podcast==NULL){
        cout << "Tidak ada lagu di playlist\n";
    }
    else{
        curr_podcast=curr_podcast->next;
        cout << "Memainkan lagu selanjutnya : " << curr_podcast->judul << endl;
    }
}

void prevNode(){
    if(curr_podcast==NULL){
        cout << "Tidak ada lagu di playlist!\n";
    }
    else{
        curr_podcast=curr_podcast->prev;
        cout << "Memainkan lagu sebelumnya : " << curr_podcast->judul << endl;
    }
}

int main()
{
    int pilih,value;
    string judul, channel;
    int durasi;

    tambahBelakang("bisnis gedang klutuk", "PODKESMAS", 10);
    tambahBelakang("bisnis milenial", "Close the Door", 20);
    tambahBelakang("nasa buka cabang di indonesia", "Makna Talks", 60);
    tambahBelakang("panutan remaja sekarang", "Rintik sedu", 120);
    tampilDepan();
    // tambahTengah("tiba-tiba judi", "Vindes", 45, 3);
    tampilDepan();

    hapusTengah(4);
    tampilDepan();

    firstNode();
    nextNode();
    prevNode();
    // tampilDurasi();

    // do{
    //     cout << "\n=============================================\n";
    //     cout << "\t\tPlayList\n";
    //     cout << "=============================================\n";
    //     cout << "1. Tambah Data di Depan\n";
    //     cout << "2. Tambah Data di Tengah\n";
    //     cout << "3. Tambah Data di Belakang\n";
    //     cout << "4. Hapus Data di Depan\n";
    //     cout << "5. Hapus Data di Tengah\n";
    //     cout << "6. Hapus Data di Belakang\n";
    //     cout << "7. Cari Data\n";
    //     cout << "8. Tampil Data dari Depan\n";
    //     cout << "9. Tampil Data dari Depan\n";
    //     cout << "10. Selesai\n";
    //     cout << "Pilihan Anda [1-10] : ";
    //     cin >> pilih;
    //     if(pilih == 1){
    //         system("clear");
    //         cout << "Masukkan Data : "; cin >> value;
    //         tambahDepan(value);
    //     }if(pilih == 2){
    //         system("clear");
    //         tampilDepan();
    //         cout << "Masukkan Data : "; cin >> value;
    //         tambahTengah(value);
    //     }if(pilih == 3){
    //         system("clear");
    //         cout << "Masukkan Data : "; cin >> value;
    //         tambahBelakang(value);
    //     }if(pilih == 4){
    //         system("clear");
    //         hapusDepan();
    //     }if(pilih == 5){
    //         system("clear");
    //         tampilDepan();
    //         hapusTengah();
    //     }if(pilih == 6){
    //         system("clear");
    //         hapusBelakang();
    //     }if(pilih == 7){
    //         system("clear");
    //         cout << "Cari Data Berapa? ";cin >> value;
    //         cariData(value);
    //     }if(pilih == 8){
    //         system("clear");
    //         cout << "Data Tampil\n";
    //         tampilDepan();
    //     }if(pilih == 9){
    //         system("clear");
    //         cout << "Data Tampil\n";
    //         tampilBelakang();
    //     }
    // }while(pilih!=10);
    
    return 0;
}

void tambahDepan(string judul, string channel, int durasi){
    dll *baru = new dll;
    
    baru->judul = judul;
    baru->channel = channel;
    baru->durasi = durasi;
    
    baru->next = NULL;
    baru->prev = NULL;
    
    if(head == NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }else{
        baru->next = head;
        head->prev = baru;
        head = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data " << judul << " Masuk di Depan!\n";
}

void tambahTengah(string judul, string channel, int durasi, int posisi){
    dll *baru = new dll;
    dll *bantu = new dll;
    dll *cur = new dll;


    baru->judul = judul;
    baru->channel = channel;
    baru->durasi = durasi;
    baru->next = NULL;
    baru->prev = NULL;

    if(head == NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }else{
        cur = head;
        int nomor = 1;

        while(nomor < posisi - 1){
            cur = cur->next;
            nomor++;
        }

        bantu = cur->next;
        cur->next = baru;
        bantu->prev = baru;
        baru->prev = cur;
        baru->next = bantu;
        

        // string after;
        // cout << "Setelah judul? "; 
        // cin >> after;
        // do{
        //     if(bantu->judul == after){
        //         baru->next=bantu->next;
        //         baru->prev = bantu;
        //         bantu->next = baru;
        //         bantu->next->prev = baru;
                
        //     }
        //     bantu = bantu->next;
        // }while(bantu!=head);
    }
}


void tambahBelakang(string judul, string channel, int durasi){
    dll *baru = new dll;

    baru->judul = judul;
    baru->channel = channel;
    baru->durasi = durasi;
    baru->next = NULL;
    baru->prev = NULL;

    if(head == NULL){
        head = baru;
        tail = baru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
        curr_podcast = head;

    }else{
        tail->next = baru;
        baru->prev = tail;
        tail=baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data " << judul << " Masuk di belakang!\n";
}

void hapusDepan(){
    dll *hapus = new dll;
    int d;
    if(head){
        if(head != tail){
            hapus = head;
            d = head->durasi;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete hapus;

        }else{
            d = head->durasi;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " Terhapus\n";
    }else{
        cout << "Data Masih Kosong!\n";
    }
}

void hapusTengah(int posisi){
    if(head == NULL){
        cout << "Data Masih Kosong!!!\n";
    }else{
        dll *bantu = new dll;
        dll *hapus = new dll;
        dll *cur = new dll;

        cur = head;
        int nomor = 1;

        while(nomor < posisi - 1){
            cur = cur->next;
            nomor++;
        }

        hapus = cur->next;
        bantu = hapus->next;
        cur->next = bantu;
        bantu->prev = cur;
        delete hapus;

    }
}

void hapusBelakang(){
    dll *hapus = new dll;
    int d;
    if(head){
        if(head != tail){
            hapus = tail;
            d = tail->durasi;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }else{
            d = head->durasi;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " Terhapus";
    }else{
        cout << "Data Masih Kosong!\n";
    }
}

void cariData(string judul){
    dll *bantu = new dll;

    bantu=head;
    do{
        if(judul == bantu->judul){
            cout << "Data " << judul << " Ketemu!!!\n";
        }

        bantu = bantu->next;
    }while(bantu!=head);
}

void tampilDepan(){
    dll *bantu;
    bantu=head;
    // while(bantu->next != head){
    //     cout << bantu->nilai << endl;
    //     bantu->next = bantu;
    // }
    cout << "===================================\n";
    if(head == NULL){
        cout << "Data Masih!!!\n";
    }else{
        do{
            cout << "Judul Podcast : " << bantu->judul << endl;
            cout << "Channel Podcast : " << bantu->channel<< endl;
            cout << "Durasi : " << bantu->durasi << " menit" << endl << endl;
            bantu = bantu->next;
        }while (bantu!=head);   
    }
    cout << "==================================\n";
    
    
}

void tampilDurasi(){
    dll *bantu = new dll;
    bantu=head;
    int data[100];
    int i=0;

    // for(int i=0; bantu!=head; i++){
    //     data[i] = bantu->durasi;
    //     cout << bantu->durasi;
    //     bantu = bantu->next;

    // }

    do{
        data[i] = bantu->durasi;
        bantu = bantu->next;
        i++;
    }while(bantu!=head);

    cout << "sorting by durasi\n";
    cout << "=======================\n";
    // cout << data[0] << endl;
    // cout << data[1] << endl;

    cout << bantu->durasi << endl;
    cout << bantu->next->durasi << endl;
    cout << bantu->next->next->durasi << endl;

    // for(int a=0; i<5; i++){
    //     cout << data[a] << endl;
    // }
    

    
}

void tampilBelakang(){
    dll *bantu;
    bantu=tail;

    cout << "==============\n";
    if(tail == NULL){
        cout << "Data Masih Kosong!!!\n";
    }else{
        do{
            cout << bantu->judul << endl;
            cout << bantu->channel<< endl;
            cout << bantu->durasi << endl;
            bantu = bantu->prev;
        }while (bantu!=tail);
    }
    cout << "\n==============\n";
}

void sortByDurasi(){
    
}