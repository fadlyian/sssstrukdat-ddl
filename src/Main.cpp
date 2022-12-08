#include <iostream>

using namespace std;

struct Podcast
{
    string judul;
    string channel;
    int durasi;

    Podcast *next;
    Podcast *prev;
};

Podcast *head = NULL;
Podcast *curr_podcast = NULL;
Podcast *tail = NULL;

void tambahDepan(string judul, string channel, int durasi);
void tambahPodcast(string judul, string channel, int durasi); // tambah podcast
void hapusDepan(); // hapus podcast teratas
void hapusPodcast(int posisi); //  hapus podcast sesuai urutan tampilan
void hapusBelakang();// hapus podcast belakang
void tampilDepan();
void tampilBelakang(); // 

// play podcast
// void cariData(string judul); // ganti putar podcast spesifik || playSpesifik
void playFirst();
void nextPodcast();
void prevPodcast();
void playPodcast(int value);

int main()
{
    int pilih,value;
    string judul;
    string channel;
    int durasi;

    tambahPodcast("soleh solihun HAMILL!!!", "PODKESMAS", 45);
    tambahPodcast("Pesan Terakhir Lord Rangga", "Close The Door", 30);
    tambahPodcast("Bisnis Gedang Klutuk", "MaknaTalks", 90);
    
    do{
        cout << "\n=========================================\n";
        cout << "=\t  PlayList Podcast";
        cout << "\n=========================================\n";
        cout << "= 1. Tambah Podcast \n";
        cout << "= 2. Hapus Podcast \n";
        cout << "= 3. Mainkan Podcast urutan Pertama \n";
        cout << "= 4. Mainkan Podcast Selanjutnya \n";
        cout << "= 5. Mainkan Podcast Sebelumnya \n";
        cout << "= 6. Mainkan Podcast dengan urutan \n";
        cout << "= 6. Tampil Urutan Podcast \n";
        cout << "===========================================\n";
        cin >> pilih;
        if (pilih == 1){
            system("clear");
            cout << "Masukkan Judul : "; cin >> judul;
            cout << "Masukkan Channel : "; cin >> channel;
            cout << "Masukkan Durasi Podcast : "; cin >> durasi;
            tambahPodcast(judul, channel, durasi);
        }else if(pilih == 2){
            system("clear");
            tampilDepan();
            cout << "Hapus Podcast dengan urutan ke? "; cin >> value;
            hapusPodcast(value);
        }else if(pilih == 3){
            system("clear");
            playFirst();
        }else if(pilih == 4){
            system("clear");
            nextPodcast();
        }else if(pilih == 5){
            system("clear");
            prevPodcast();
        }else if(pilih == 6){
            system("clear");
            cout << "Mainkan Podcast dengan urutan ke? "; cin >> value;
            playPodcast(value);
        }else if(pilih == 7){
            system("clear");
            tampilDepan();
        }
        
    }while(pilih!=10);
    
    return 0;
}

void tambahDepan(string judul, string channel, int durasi){
    Podcast *baru = new Podcast;
    
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

void tambahPodcast(string judul, string channel, int durasi){
    Podcast *baru = new Podcast;    

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
    Podcast *hapus = new Podcast;
    string jd,jc;
    int d;
    if(head){
        if(head != tail){
            hapus = head;
            jd = head->judul;
            jc = head->channel;
            d = head->durasi;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete hapus;

        }else{
            jd = head->judul;
            d = head->durasi;
            head = NULL;
            tail = NULL;
            curr_podcast = NULL;
        }
        cout << "podcast " << jd << " Terhapus\n";
    }else{
        cout << "Data Masih Kosong!\n";
    }
}

void hapusPodcast(int posisi){
    if(head == NULL){
        cout << "Data Masih Kosong!!!\n";
    }else{
        Podcast *bantu = new Podcast;
        Podcast *hapus = new Podcast;
        Podcast *cur = new Podcast;

        cur = head;
        int nomor = 1;
        
        if(posisi == 1){
            hapusDepan();
            head == NULL;
        }else{

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
}

void hapusBelakang(){
    Podcast *hapus = new Podcast;
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
    Podcast *bantu = new Podcast;

    bantu=head;
    do{
        if(judul == bantu->judul){
            cout << "Data " << judul << " Ketemu!!!\n";
        }

        bantu = bantu->next;
    }while(bantu!=head);
}

void tampilDepan(){
    Podcast *bantu;
    bantu=head;
    // while(bantu->next != head){
    //     cout << bantu->nilai << endl;
    //     bantu->next = bantu;
    // }
    cout << "===================================\n";
    if(head == NULL){
        cout << "Data Masih kosong!!!\n";
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

void tampilBelakang(){
    Podcast *bantu;
    bantu=tail;

    cout << "==============\n";
    if(tail == NULL){
        cout << "Data Masih Kosong!!!\n";
    }else{
        do{
            cout << "Judul : " << bantu->judul << endl;
            cout << "Channel : " << bantu->channel<< endl;
            cout << "Durasi : " << bantu->durasi << endl;
            bantu = bantu->prev;
        }while (bantu!=tail);
    }
    cout << "\n==============\n";
}

void playFirst(){
    if(head==NULL){
        cout << "Playlist masih kosong\n";
    }else{
        cout << "=================================================\n";
        cout << "Memainkan Podcast Pertama\n";
        cout << "=================================================\n";
        cout << head->judul << endl;
        cout << head->channel << endl;
        cout << "00:00 ●━━━━━━━━━━━━ " << head->durasi << ":00" << endl;
        cout << "=================================================\n";
    }
}

void nextPodcast(){
    if(curr_podcast==NULL){
        cout << "Tidak ada lagu di playlist\n";
    }
    else{
        curr_podcast=curr_podcast->next;
        cout << "=================================================\n";
        cout << "Memainkan Podcast Sebelumnya\n";
        cout << "=================================================\n";
        cout << curr_podcast->judul << endl;
        cout << curr_podcast->channel << endl;
        cout << "00:00 ●━━━━━━━━━━━━ " << curr_podcast->durasi << ":00" << endl;
        cout << "=================================================\n";
    }
}

void prevPodcast(){
    if(curr_podcast==NULL){
        cout << "Tidak ada lagu di playlist!\n";
    }
    else{
        curr_podcast=curr_podcast->prev;
        cout << "=================================================\n";
        cout << "Memainkan Podcast Sebelumnya\n";
        cout << "=================================================\n";
        cout << curr_podcast->judul << endl;
        cout << curr_podcast->channel << endl;
        cout << "00:00 ●━━━━━━━━━━━━ " << curr_podcast->durasi << ":00" << endl;
        cout << "=================================================\n";
    }
}

void playPodcast(int posisi){
        curr_podcast = head;
    
        int nomor = 1;

        // tranversing
        while(nomor < posisi ){
            curr_podcast = curr_podcast->next;
            nomor++;
        }

        cout << "=================================================\n";
        cout << "Memainkan Podcast " << curr_podcast->judul << endl;
        cout << "=================================================\n";
        cout << curr_podcast->judul << endl;
        cout << curr_podcast->channel << endl;
        cout << "00:00 ●━━━━━━━━━━━━ " << curr_podcast->durasi << ":00" << endl;
        cout << "=================================================\n";
    
}