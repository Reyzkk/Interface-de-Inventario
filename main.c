#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Constantes
#define MAX_ITEMS 10
#define MAX_STRING_NAME 50
#define WEIGHT_MAX 100

// Tipos de item
typedef enum {
    TYPE_AMMO = 1,
    TYPE_VEST = 2,
    TYPE_GUN = 3,
    TYPE_MEDICKIT = 4,
    TYPE_HELMET = 5 
} ItemType;

// Limites separados
#define MAX_AMMO     300
#define MAX_VEST     1
#define MAX_GUN      1
#define MAX_MEDICKIT 5
#define MAX_HELMET   1

const char* ItemTypeNames[] = {"Munição", "Colete", "Arma", "Kit Médico", "Capacete"};
int TypeArrayLength = sizeof(ItemTypeNames) / sizeof(ItemTypeNames[0]);

typedef enum{
    INSERT = 1,
    REMOVE = 2,
    LIST = 3,
    CHECK_WEIGHT = 4,
    EXIT = 5
} Menu;

// Estrutura de item
typedef struct{
    char name[MAX_STRING_NAME];
    ItemType type;
    int count;
    float weight;
} Item;

// Configurações do programa
int Program_Execute = 1;
int inputMenu;

// Inventário
Item Backpack[MAX_ITEMS];
int count_slot = 0;

// Função para mudar cor no console
void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Limpa buffer do teclado
void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pausa
void Pause(){
    printf("Pressione Enter para continuar...");
    ClearBuffer();
    getchar();
}

// Limpa tela
void Clear(){
    for(int i = 0; i < 50; i++){
        printf("\n");
    }
}

// Animação: texto digitando
void TypeText(const char *text, int speed) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(speed);
    }
}

// Animação: barra de carregamento
void LoadingBar(const char *msg, int steps, int delay) {
    printf("%s [", msg);
    for (int i = 0; i < steps; i++) {
        printf("■");
        fflush(stdout);
        Sleep(delay);
    }
    printf("] OK\n");
}

// Boot de inicialização
void BootSequence() {
    Clear();
    SetColor(11);
    TypeText("Inicializando INTERFACE DE MOCHILA...\n", 40);
    Sleep(400);
    LoadingBar("Carregando módulos principais", 15, 60);
    Sleep(200);
    LoadingBar("Carregando banco de itens", 12, 50);
    Sleep(200);
    LoadingBar("Ativando interface do usuário", 18, 40);
    SetColor(10);
    TypeText("\n[✔] SISTEMA ONLINE.\n", 30);
    SetColor(7);
    Sleep(1000);
}

// Efeito de processamento
void Processing(const char *msg) {
    printf("\n%s", msg);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(400);
    }
    printf("\n");
}

// Menu principal
void Menu_Interface(){
    SetColor(11); // ciano 
    printf("\n===========================================\n");
    printf("   >>  SISTEMA: INTERFACE DE MOCHILA  <<\n");
    printf("            Slots usados (%d/%d)\n", count_slot, MAX_ITEMS);
    printf("===========================================\n");
    SetColor(7); // branco
    printf("  (1)  [+] ADICIONAR ITEM\n");
    printf("  (2)  [-] REMOVER ITEM\n");
    printf("  (3)  [*] MOSTRAR INVENTÁRIO\n");
    printf("  (4)  [#] CHECAR PESO TOTAL\n");
    printf("  (5)  [X] SAIR\n");
    printf("-------------------------------------------\n");
    printf("  SELECIONE UMA OPÇÃO: ");
}

// Mostrar inventário
void ShowInventory(){
    // Cabeçalho
    SetColor(14); // amarelo
    printf("\n┌────┬────────────────────────┬────────────────┬───────────────┐\n");
    printf("│ ID │ NOME DO ITEM           │ TIPO           │ QUANTIDADE    │\n");
    printf("├────┼────────────────────────┼────────────────┼───────────────┤\n");

    // Itens
    for (int i = 0; i < count_slot; i++) {
        switch(Backpack[i].type) {
            case TYPE_AMMO: SetColor(15); break;      // branco
            case TYPE_VEST: SetColor(9); break;       // azul
            case TYPE_GUN: SetColor(12); break;       // vermelho
            case TYPE_MEDICKIT: SetColor(10); break;  // verde
            case TYPE_HELMET: SetColor(13); break;    // rosa
            default: SetColor(7); break;              // branco padrão
        }

        printf("│ %-2d │ %-22s │ %-14s │ %-13d │\n",
               i + 1,
               Backpack[i].name,
               ItemTypeNames[Backpack[i].type - 1],
               Backpack[i].count);
    }

    // Rodapé
    SetColor(14);
    printf("└────┴────────────────────────┴────────────────┴───────────────┘\n");

    SetColor(7); // volta ao branco normal
}

// Inserir itens
void InsertItems(){
    Clear();
    if(count_slot >= MAX_ITEMS){
        Clear();
        SetColor(12); printf("\n[✖] Slot cheio! Não é possível adicionar mais itens.\n");
        SetColor(7);
        Pause();
        return;
    }

    Item createItem;

    Clear();
    printf("Digite o NOME do item: \n>"); 
    scanf("%s", createItem.name); ClearBuffer();

    Clear();
    printf("Selecione o TIPO do item: \n"); 
    for(int i = 0; i < TypeArrayLength; i++){
        printf("[%d] |%s|\n", i + 1, ItemTypeNames[i]);
    }
    scanf("%d", &createItem.type); ClearBuffer();

    Clear();
    printf("Digite a QUANTIDADE do item: \n>"); 
    scanf("%d", &createItem.count); ClearBuffer();

    Backpack[count_slot] = createItem; 
    count_slot++;

    Processing("Adicionando item ao inventário");
    SetColor(10); printf("\n[✔] Item adicionado com sucesso!\n");
    SetColor(7);
    Pause();
}

// Listar itens (com opção de inserir se vazio)
void ListItems(){
    Clear();
    if(count_slot < 1){
        char opt;
        ClearBuffer();

        SetColor(12);
        printf("\n┌───────────────────────────────────────────┐\n");
        printf("│ ⚠  INVENTÁRIO VAZIO                      │\n");
        printf("└───────────────────────────────────────────┘\n");

        SetColor(7);
        printf("Deseja adicionar itens? (s/n): \n>");
        scanf(" %c", &opt);

        if(opt == 'N'|| opt == 'n') return;
        else if(opt == 'S' || opt == 's'){
            InsertItems();
            Clear();
            ShowInventory();
            Pause();
            return;
        }
    }
    Clear();
    ShowInventory();
    Pause();
}

// Remover itens
void RemoveItems() {

    if (count_slot == 0) {
        Clear();
        SetColor(12);
        printf("\n⚠ Inventário vazio! Nenhum item para remover.\n");
        SetColor(7);
        Pause();
        return;
    }

    ShowInventory();

    char target[MAX_STRING_NAME];
    printf("\nDigite o NOME do item que deseja remover: ");
    scanf("%s", target);
    ClearBuffer();

    int index = -1;
    for (int i = 0; i < count_slot; i++) {
        if (strcasecmp(Backpack[i].name, target) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        SetColor(12);
        printf("\n❌ Item '%s' não encontrado no inventário.\n", target);
        SetColor(7);
        Pause();
        return;
    }

    for (int i = index; i < count_slot - 1; i++) {
        Backpack[i] = Backpack[i + 1];
    }

    count_slot--;

    Processing("Removendo item do inventário");
    SetColor(10);
    printf("\n✅ Item '%s' removido com sucesso!\n", target);
    SetColor(7);
    Pause();
}

// Main
int main(){
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleTitle("INTERFACE DE MOCHILA");

    // === ITENS INICIAIS ===
    Item Slot1 = {"Pistola", TYPE_GUN, 1, 3.5};
    Item Slot2 = {"Colete Nivel 2", TYPE_VEST, 1, 5.0};
    Item Slot3 = {"Kit Médico", TYPE_MEDICKIT, 2, 1.2};

    Backpack[0] = Slot1;
    Backpack[1] = Slot2;
    Backpack[2] = Slot3;

    count_slot = 3; //3 slots ocupados

    Backpack[0] = Slot1;
    Backpack[1] = Slot2;
    Backpack[2] = Slot3;
    BootSequence(); // animação de inicialização
    
    
    SetColor(11);
    TypeText("\nCarregando inventário inicial...\n", 40);

    Sleep(500);
    ShowInventory();
    Pause();

    do {
        Clear();
        Menu_Interface();
        scanf("%d", &inputMenu);

        switch (inputMenu)
        {
            case INSERT: InsertItems(); break;
            case REMOVE: RemoveItems(); break;
            case LIST: ListItems(); break;
            case CHECK_WEIGHT: SetColor(13); printf("Função Indisponivel...\n"); Pause(); Clear(); break;
            case EXIT: Program_Execute = 0; break;
            default: break;
        }

    } while (Program_Execute);

    // Animação de saída
    Clear();
    SetColor(14);
    Processing("Salvando dados da mochila");
    Sleep(500);
    TypeText("\n[✔] MOCHILA SALVA.\n", 40);
    Sleep(300);
    TypeText("[✔] DESCONECTANDO INTERFACE...\n", 40);
    Sleep(400);
    SetColor(10);
    TypeText("\n>> SISTEMA DESLIGADO <<\n", 60);
    SetColor(7);
    Sleep(1000);

    return 0;
}
