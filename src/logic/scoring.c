#include <stdio.h>
#include <string.h>
#include "scoring.h"

static int hitung_poin_penghasilan(long penghasilan) {
    if (penghasilan < 500000)                              return 40;
    if (penghasilan >= 500000  && penghasilan < 1000000)  return 30;
    if (penghasilan >= 1000000 && penghasilan < 2000000)  return 20;
    if (penghasilan >= 2000000 && penghasilan < 3000000)  return 10;
    return 0;
}

static int hitung_poin_pekerjaan(const char* pekerjaan) {
    if (strcasecmp(pekerjaan, "Tidak Bekerja")  == 0) return 25;
    if (strcasecmp(pekerjaan, "Petani")         == 0) return 20;
    if (strcasecmp(pekerjaan, "Nelayan")        == 0) return 20;
    if (strcasecmp(pekerjaan, "Petani/Nelayan") == 0) return 20;
    if (strcasecmp(pekerjaan, "Wiraswasta")     == 0) return 15;
    if (strcasecmp(pekerjaan, "Pegawai Swasta") == 0) return 8;
    if (strcasecmp(pekerjaan, "PNS")            == 0) return 0;
    return 0;
}

static int hitung_poin_tanggungan(int jumlah) {
    if (jumlah >= 5)                return 20;
    if (jumlah >= 3 && jumlah <= 4) return 15;
    if (jumlah >= 1 && jumlah <= 2) return 10;
    return 0;
}

static int hitung_poin_rumah(const char* kondisi_rumah) {
    if (strcasecmp(kondisi_rumah, "Tidak Layak Huni") == 0) return 15;
    if (strcasecmp(kondisi_rumah, "Tidak Layak")      == 0) return 15;
    return 0; // Layak Huni
}

int hitung_skor(Warga* w) {
    if (w == NULL) return 0;

    int p1 = hitung_poin_penghasilan(w->penghasilan);
    int p2 = hitung_poin_pekerjaan(w->pekerjaan);
    int p3 = hitung_poin_tanggungan(w->jumlah_tanggungan);
    int p4 = hitung_poin_rumah(w->kondisi_rumah);

    w->total_skor = p1 + p2 + p3 + p4;
    return w->total_skor;
}

int konversi_ke_desil(int skor) {
    if (skor >= 80) return 1;
    if (skor >= 60) return 3;
    if (skor >= 40) return 5;
    if (skor >= 20) return 7;
    return 8;
}