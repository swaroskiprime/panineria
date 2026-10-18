#include <stdio.h>

void sconti(int n, float *totale, int numMenu, int numPanini);
int leggiGiorno(char gSettimana[]);
void menu();

int main(){
    int scelta, n = 0;
    float totale = 0.0;
    char gSettimana[10];

    //contatori per i menu e i panini
    int numMenu = 0;
    int numPanini = 0;

    menu();

    do {
        printf("Inserisci il numero del prodotto da aggiungere:\n");
        scanf("%d", &scelta);
        switch(scelta) {
            case 1:
                totale += 18.90;
                numMenu++;
                printf("Menu Amatriccio aggiunto al tuo ordine\n");
                break;
            case 2:
                totale += 13.90;
                numPanini++;
                printf("Panino Amatriccio aggiunto al tuo ordine\n");
                break;
            case 3:
                totale += 18.90;
                numMenu++;
                printf("Menu Carbonaro89 aggiunto al tuo ordine\n");
                break;
            case 4:
                totale += 13.90;
                numPanini++;
                printf("Panino Carbonaro89 aggiunto al tuo ordine\n");
                break;
            case 5:
                totale += 18.90;
                numMenu++;
                printf("Menu Bacon Bacon aggiunto al tuo ordine\n");
                break;
            case 6:
                totale += 13.90;
                numPanini++;
                printf("Panino Bacon Bacon aggiunto al tuo ordine\n");
                break;
            case 7:
                totale += 15.90;
                numMenu++;
                printf("Menu Chicken aggiunto al tuo ordine\n");
                break;
            case 8:
                totale += 13.90;
                numPanini++;
                printf("Panino Gamer Pollo aggiunto al tuo ordine\n");
                break;
            case 9:
                totale += 3.90;
                int salsa = 0;
                printf("Vuoi anche la salsa?(S = 1/N = 0)\n");
                scanf("%d", &salsa);
                if (salsa == 1) {
                    int s;
                    printf("Scegli:\n");
                    printf("1. Ketchup (0.50 EUR)\n");
                    printf("2. Maionese (0.50 EUR)\n");
                    printf("3. Salsa ciccio (1.00 EUR)\n");
                    printf("4. Salsa BBQ (1.00 EUR)\n");
                    scanf("%d", &s);
                    if (s == 1 || s == 2)
                        totale += 0.50;
                    else if (s == 3 || s == 4)
                        totale += 1.00;
                }
                printf("Aggiunto al tuo ordine\n");
                break;
            case 10:
                totale += 4.50;
                printf("Onion Rings aggiunti al tuo ordine\n");
                break;
            case 11:
                totale += 5.90;
                printf("Nuggets (5pz) aggiunti al tuo ordine\n");
                break;
            case 12:
                totale += 10.90;
                printf("Nuggets (10pz) aggiunti al tuo ordine\n");
                break;
            case 13:
                totale += 1.50;
                printf("Acqua naturale aggiunta al tuo ordine\n");
                break;
            case 14:
                totale += 1.50;
                printf("Acqua frizzante aggiunta al tuo ordine\n");
                break;
            case 15:
                totale += 2.50;
                printf("Coca-Cola aggiunta al tuo ordine\n");
                break;
            case 16:
                totale += 2.50;
                printf("Coca-Cola zero aggiunta al tuo ordine\n");
                break;
            case 17:
                totale += 2.50;
                printf("Sprite aggiunta al tuo ordine\n");
                break;
            case 18:
                totale += 2.50;
                printf("Fanta aggiunta al tuo ordine\n");
                break;
            case 0:
                printf("Fine ordine\n");
                break;
            default:
                printf("Scelta non valida. Riprova\n");
        }
    } while(scelta != 0);

    printf("Inserisci il giorno della settimana\n");
    scanf("%s", gSettimana); //legge la stringa in modo pulito

    n = leggiGiorno(gSettimana);

    //applichiamo gli sconti se previsti
    sconti(n, &totale, numMenu, numPanini);

    printf("Totale = %.2f EUR\n", totale);
    return 0;
}
void menu() {
    printf("   BENVENUTI ALLA PANTERA'S BURGER   \n");
    printf(" 1. Menu Amatriccio      (18.90 EUR)\n");
    printf(" 2. Amatriccio           (13.90 EUR)\n");
    printf(" 3. Menu Carbonaro89     (18.90 EUR)\n");
    printf(" 4. Carbonaro89          (13.90 EUR)\n");
    printf(" 5. Menu Bacon Bacon     (18.90 EUR)\n");
    printf(" 6. Bacon Bacon          (13.90 EUR)\n");
    printf(" 7. Menu Chicken         (15.90 EUR)\n");
    printf(" 8. Gamer pollo          (13.90 EUR)\n");
    printf(" SIDES & CONTORNI:\n");
    printf(" 9. Regular Fries        ( 3.90 EUR)\n");
    printf("10. Onion Rings          ( 4.50 EUR)\n");
    printf("11. Nuggets (5pz)        ( 5.90 EUR)\n");
    printf("12. Nuggets (10pz)       (10.90 EUR)\n");
    printf(" BIBITE:\n");
    printf("13. Acqua naturale       ( 1.50 EUR)\n");
    printf("14. Acqua frizzante      ( 1.50 EUR)\n");
    printf("15. Coca-Cola            ( 2.50 EUR)\n");
    printf("16. Coca-Cola Zero       ( 2.50 EUR)\n");
    printf("17. Sprite               ( 2.50 EUR)\n");
    printf("18. Fanta                ( 2.50 EUR)\n");
    printf(" 0. Termina l'ordine\n");
}

int leggiGiorno(char gSettimana[]) {
    //1 = venerdì, 2 = sabato, 3 = domenica, 0 = altri giorni
    switch (gSettimana[0]) {
        case 'V':
        case 'v':
            return 1;
        case 'S':
        case 's':
            return 2;
        case 'D':
        case 'd':
            return 3;
        default:
            printf("Nessuno sconto previsto per questo giorno\n");
            return 0;
    }
}

void sconti(int n, float *totale, int numMenu, int numPanini) {
    if (n == 1) {
        //venerdì: menu scontati di 3 euro
        float sconto = numMenu * 3.0;
        *totale -= sconto;
        printf("Sconto di 3 euro su tutti i menu che hai selezionato\n");
    }
    else if (n == 2){
        //sabato: panini scontati di 2 euro
        float sconto = numPanini * 2.0;
        *totale -= sconto;
        printf("Sconto di 2 euro su ogni panino che hai selezionato\n");
    } else if (n == 3) {
        //domenica: sconto del 10% sul totale
        float sconto = (*totale) *0.10;
        *totale -= sconto;
        printf("Sconto del 10%% sul totale\n");
    }
}
