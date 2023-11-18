#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<windows.h>        for windows devices 

#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define CYAN_TEXT "\x1b[36m"
#define YELLOW_TEXT "\x1b[33m"
#define BLUE_TEXT "\x1b[34m"
#define MAGENTA_TEXT "\x1b[35m"
#define RESET_TEXT "\x1b[0m"

typedef struct node{
        char data[50];
        struct node* link;
    }node;

void add_at_end(struct node* head, const char* sample){
    struct node* ptr = head;
    struct node* temp= malloc(sizeof(struct node ));
    strcpy(temp->data,sample);
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;

    }
    ptr->link=temp;
 }

 void insert_at_beg(struct node** head,const char* data){
    struct node *ptr = malloc(sizeof(struct node ));
    strcpy(ptr->data,data);
    ptr->link=*head;
    *head=ptr;
    

 }

const char* del_at_pos(struct node* head,int key){
    struct node* ptr = malloc(sizeof(struct node ));
    struct node* temp = malloc(sizeof(struct node ));
    int i=1;
    ptr=head;
    if (head==NULL){
      printf("no head");
    }
    else if (key==1){
      head= head->link;
      
      return ptr->data;
    }
    else{
    while(i<key){
      temp=ptr;
      ptr=ptr->link;
      i++;
    }
   temp->link=ptr->link;
    char* sample;
   strcpy(sample,ptr->data);
   
   free(ptr);
   head=temp;
   return sample;
    }
    return " ";
 }
const char* display_at_pos(struct node* head,int key){
    struct node* ptr = malloc(sizeof(struct node ));
    
    int i=1;
    ptr=head;
    if (head==NULL){
      return "no element";
    }
    else if (key==1){
      return head->data;
    }
    else{
    while(i<key && ptr!=NULL){
      
      ptr=ptr->link;
      i++;
    }
   return ptr->data;
   
   
   
    }
    
 }



  void count(struct node* head){
   if (head==NULL){
      printf("empty list");
   }
   else{
    int i=0;
    while(head!=NULL){
            i++;
        printf("node %d = %s\n",i,head->data);
        
        head=head->link;
        
    }
    printf("total number of nodes is = %d",i);
   }

 }



int word_select(int upper) { 
    
    
        int num = (rand() %  (upper - 2 + 1)) + 2; 
       
        return num;
    
} 
int list_selector() { 
    
    
        int nume = (rand() %  (2 - 1 + 1)) + 1; 
       
        return nume;
    
} 
const char* convert_string(char sample[]){
    const char* word = sample;
    return word;

}
int  count_nodes(struct node* head){
   if (head==NULL){
      return 0;
   }
   else{
    int i=0;
    while(head!=NULL){
            i++;
        
        
        head=head->link;
        
    }
    return i;
   }
   

 }
int verbal_memory(){
    int points =0,lives=3;
  node* new = (node*)malloc(sizeof(node));
  node* seen = (node*)malloc(sizeof(node));
  char games[11][20];
  int k=0;
     
  new=NULL;
  seen=NULL;
  printf(RED_TEXT"\n          -------------MEMORY GAME-----------------          \n\n\n"RESET_TEXT);
  printf(RESET_TEXT"GENRES AVAILABLE:\n\n");
  printf(GREEN_TEXT"1) DSA TOPICS\n");
  printf("2) ANIME\n");
  printf("3) ANIMALS\n");
  printf("4) MOVIES\n");
  printf("5) PLACES\n\n"RESET_TEXT);


  int genre_choosing;
  printf("CHOOSE THE GENRE (enter the serial number ): ");
  scanf("%d",&genre_choosing); 
  printf("\e[1;1H\e[2J");// this line clears console 
  //system("cls")  for windows 

   insert_at_beg(&new,convert_string("begin"));

    if(genre_choosing == 1){

      
      add_at_end(new,convert_string("LINKED LIST"));
      add_at_end(new,convert_string("TREES"));
      add_at_end(new,convert_string("STACKS"));
      add_at_end(new,convert_string("QUEUE"));
      add_at_end(new,convert_string("SPARSE MATRIX"));
      add_at_end(new,convert_string("BINARY TREE"));
      add_at_end(new,convert_string("GRAPHS"));
      add_at_end(new,convert_string("HEAP"));
      add_at_end(new,convert_string("DJIKSTRA'S ALGORITHM"));
      add_at_end(new,convert_string("BACKTRACKING"));
      add_at_end(new,convert_string("DIVIDE AND CONQUER"));
      add_at_end(new,convert_string("PRIORITY QUEUE"));  
      add_at_end(new,convert_string("PRIM'S ALGORITHM"));
      add_at_end(new,convert_string("DYNAMIC PROGRAMMING"));
      add_at_end(new,convert_string("LINEAR REGRESSION"));
      add_at_end(new,convert_string("LOGISTIC REGRESSION"));
      add_at_end(new,convert_string("MULTIPLE REGRESSION"));
      add_at_end(new,convert_string("LARGE LANGUAGE MODELS"));
      add_at_end(new,convert_string("TRANSFORMERS"));
      add_at_end(new,convert_string("LSTM"));
      add_at_end(new,convert_string("K-NEAREST NEIGHBOURS"));
      add_at_end(new,convert_string("RANDOM FOREST"));
      add_at_end(new,convert_string("SPLAY TREE"));
      add_at_end(new,convert_string("SPARSE MATRIX"));
      add_at_end(new,convert_string("GRADIENT DESCENT"));
      add_at_end(new,convert_string("CNN"));
      add_at_end(new,convert_string("NEURAL NETWORKS"));
      add_at_end(new,convert_string("SUPPORT VECTOR MACHINE"));
      add_at_end(new,convert_string("NAIVE BAYES CLASSSIFIER"));
      add_at_end(new,convert_string("BAYESIAN INFERENCE"));
      add_at_end(new,convert_string("CLUSTER ANALYSIS"));
      add_at_end(new,convert_string("DECISION MAKING"));
      add_at_end(new,convert_string("SEGMENT TREE"));
      add_at_end(new,convert_string("BREADTH FIRST SEARCH"));
      add_at_end(new,convert_string("DEPTH FIRST SEARCH"));
      add_at_end(new,convert_string("SELECTION SORT"));
      add_at_end(new,convert_string("HASHING"));
      add_at_end(new,convert_string("DOUBLY LINKED LIST"));
      add_at_end(new,convert_string("CIRCULAR QUEUE"));
      add_at_end(new,convert_string("SKIP LIST"));
      add_at_end(new,convert_string(""));
      
    }

    else if(genre_choosing == 2){
          add_at_end(new,convert_string("SUKUNA"));
        add_at_end(new,convert_string("TOJI"));
        add_at_end(new,convert_string("MEGUMI"));
        add_at_end(new,convert_string("BEERUS"));
        add_at_end(new,convert_string("YUTA"));
        add_at_end(new,convert_string("PANDA"));
        add_at_end(new,convert_string("MEI MEI"));
        add_at_end(new,convert_string("MAI"));
        add_at_end(new,convert_string("MADARA"));
        add_at_end(new,convert_string("KISAME"));
        add_at_end(new,convert_string("EREN"));
        add_at_end(new,convert_string("MIKASA"));
        add_at_end(new,convert_string("SASHA"));
        add_at_end(new,convert_string("CONNIE"));
        add_at_end(new,convert_string("LEVI"));
        add_at_end(new,convert_string("ARMIN"));
        add_at_end(new,convert_string("ZEKE"));
        add_at_end(new,convert_string("PIECK"));
        add_at_end(new,convert_string("MIYAMURA"));
        add_at_end(new,convert_string("GOJO"));
        add_at_end(new,convert_string("YUJI"));
        add_at_end(new,convert_string("MEGUMI"));
        add_at_end(new,convert_string("NANAMI"));
        add_at_end(new,convert_string("NOBARA"));
        add_at_end(new,convert_string("GETO"));
        add_at_end(new,convert_string("SHOKO"));
        add_at_end(new,convert_string("MEI MEI"));
        add_at_end(new,convert_string("MAKI"));
        add_at_end(new,convert_string("TODO"));
        add_at_end(new,convert_string("SHISUI"));
        add_at_end(new,convert_string("JIRAIYA"));
        add_at_end(new,convert_string("NARUTO"));
        add_at_end(new,convert_string("SASUKE"));
        add_at_end(new,convert_string("GOKU"));
        add_at_end(new,convert_string("SAITAMA"));
        add_at_end(new,convert_string("HASHIRAMA"));
        add_at_end(new,convert_string("TOBIRAMA"));
        add_at_end(new,convert_string("TSUNADE"));
        add_at_end(new,convert_string("GIYUU"));
        add_at_end(new,convert_string("MINATO"));
        add_at_end(new,convert_string("KUSHINA"));
      
        add_at_end(new,convert_string("EIZEN"));
        add_at_end(new,convert_string("GABIMARU"));
        add_at_end(new,convert_string("SHIN"));
    }

    else if(genre_choosing == 3){

        add_at_end(new,convert_string("LION"));
        add_at_end(new,convert_string("TIGER"));
        add_at_end(new,convert_string("wOLF"));
        add_at_end(new,convert_string("DOG"));
        add_at_end(new,convert_string("CAT"));
        add_at_end(new,convert_string("BEAR"));
        add_at_end(new,convert_string("CHEETAH"));
        add_at_end(new,convert_string("LEOPARD"));
        add_at_end(new,convert_string("JAGUAR"));
        add_at_end(new,convert_string("SHARK"));
        add_at_end(new,convert_string("COW"));
        add_at_end(new,convert_string("BUFFALO"));
        add_at_end(new,convert_string("GOAT"));
        add_at_end(new,convert_string("GIRAFFE"));
        add_at_end(new,convert_string("RHINO"));
        add_at_end(new,convert_string("MONKEY"));
        add_at_end(new,convert_string("CHIMPANZEE"));
        add_at_end(new,convert_string("GORILLA"));
        add_at_end(new,convert_string("SNAKE"));
        add_at_end(new,convert_string("DINOSAUR"));
        add_at_end(new,convert_string("ELEPHANT"));
        add_at_end(new,convert_string("PLATYPUS"));
        add_at_end(new,convert_string("OX"));
        add_at_end(new,convert_string("EAGLE"));
        add_at_end(new,convert_string("SPARROW"));
        add_at_end(new,convert_string("HONEYBADGER"));
        add_at_end(new,convert_string("BISON"));
        add_at_end(new,convert_string("ELK"));
        add_at_end(new,convert_string("SEA LION"));
        add_at_end(new,convert_string("SEAL"));
        add_at_end(new,convert_string("BLUE WHALE"));
        add_at_end(new,convert_string("PENGUIN"));
        add_at_end(new,convert_string("DODO"));
        add_at_end(new,convert_string("HYENAS"));
        add_at_end(new,convert_string("WOLF"));
        add_at_end(new,convert_string("BABOON"));
        add_at_end(new,convert_string("RABBIT"));
        add_at_end(new,convert_string("GHARIYAL"));
        add_at_end(new,convert_string("CAPYBARA"));
        add_at_end(new,convert_string("PORCUPINE"));
    }

    else if(genre_choosing == 4){

        add_at_end(new,convert_string("TRANSFORMERS"));
        add_at_end(new,convert_string("ANGELS & DEMONS"));
        add_at_end(new,convert_string("INFERNO"));
        add_at_end(new,convert_string("SHAWSHANK REDEMPTION"));
        add_at_end(new,convert_string("SPOTLIGHT"));
        add_at_end(new,convert_string("THE PRESTIGE"));
        add_at_end(new,convert_string("INTERSTELLAR"));
        add_at_end(new,convert_string("DJANGO UNCHAINED"));
        add_at_end(new,convert_string("BARBIE"));
        add_at_end(new,convert_string("WOLF OF WALL STREET"));
        add_at_end(new,convert_string("PULP FICTION"));
        add_at_end(new,convert_string("THE DARK KNIGHT"));
        add_at_end(new,convert_string("RESERVOIR DOGS"));
        add_at_end(new,convert_string("KILL BILL"));
        add_at_end(new,convert_string("SE7EN"));
        add_at_end(new,convert_string("ITALIAN JOB"));
        add_at_end(new,convert_string("OCEANS 11"));
        add_at_end(new,convert_string("HOSTEL"));
        add_at_end(new,convert_string("MEN IN BLACK"));
        add_at_end(new,convert_string("RUSH HOUR"));
        add_at_end(new,convert_string("PURSUIT OF HAPPYNESS"));
        add_at_end(new,convert_string("HORRIBLE BOSSES"));
        add_at_end(new,convert_string("GIFTED"));
        add_at_end(new,convert_string("THE NOTEBOOK"));
        add_at_end(new,convert_string("FORREST GUMP"));
        add_at_end(new,convert_string("AGENT SAI SRINIVAS ATHREYA"));
        add_at_end(new,convert_string("OPPENHEIMER"));
        add_at_end(new,convert_string("KILLERS OF THE FLOWER MOON"));
        add_at_end(new,convert_string("BIRDMAN"));
        add_at_end(new,convert_string("MUNNA BHAI MBBS"));
        add_at_end(new,convert_string("GLADIATOR"));
        add_at_end(new,convert_string("ONCE UPON A TIME IN HOLLYWOOD"));
        add_at_end(new,convert_string("UNTHINKABLE"));
        add_at_end(new,convert_string("UNSTOPPABLE"));
        add_at_end(new,convert_string("NEVER BACK DOWN"));
        add_at_end(new,convert_string("FIGHT CLUB"));
        add_at_end(new,convert_string("MR AND MRS SMITH"));
        add_at_end(new,convert_string("7 YEARS IN TIBET"));
        add_at_end(new,convert_string("GODZILLA"));
        add_at_end(new,convert_string("PARASITE"));

    }
        else if(genre_choosing == 5){

            add_at_end(new,convert_string("PARIS"));
            add_at_end(new,convert_string("BENGALURU"));
            add_at_end(new,convert_string("HYDERABAD"));
            add_at_end(new,convert_string("CHENNAI"));
            add_at_end(new,convert_string("SHIMLA"));
            add_at_end(new,convert_string("ADDIS ABABA"));
            add_at_end(new,convert_string("MANDYA"));
            add_at_end(new,convert_string("BAGALKHOT"));
            add_at_end(new,convert_string("MANGALURU"));
            add_at_end(new,convert_string("MYSURU"));
            add_at_end(new,convert_string("HIMACHAL PRADESH"));
            add_at_end(new,convert_string("NEW DELHI"));
            add_at_end(new,convert_string("CHANDIGARH"));
            add_at_end(new,convert_string("MUMBAI"));
            add_at_end(new,convert_string("KOLKATA"));
            add_at_end(new,convert_string("DHARMSALA"));
            add_at_end(new,convert_string("KOLKATA"));
            add_at_end(new,convert_string("LADAKH"));
            add_at_end(new,convert_string("MADURAI"));
            add_at_end(new,convert_string("CHANDIGARH"));
            add_at_end(new,convert_string("DELHI"));
            add_at_end(new,convert_string("KANYAKUMARI"));
            add_at_end(new,convert_string("RAMESHWARAM"));
            add_at_end(new,convert_string("SHILLONG"));
            add_at_end(new,convert_string("DARJEELING"));
            add_at_end(new,convert_string("BOSTON"));
            add_at_end(new,convert_string("PUNE"));
            add_at_end(new,convert_string("BHOPAL"));
            add_at_end(new,convert_string("VIJAYWADA"));
            add_at_end(new,convert_string("GOA"));
            add_at_end(new,convert_string("VARANASI"));
            add_at_end(new,convert_string("DEHRA DUN"));
            add_at_end(new,convert_string("JAIPUR"));
            add_at_end(new,convert_string("JODHPUR"));
            add_at_end(new,convert_string("AMRITSAR"));
            add_at_end(new,convert_string("NEW YORK"));
            add_at_end(new,convert_string("KANPUR"));
            add_at_end(new,convert_string("PATNA"));
            add_at_end(new,convert_string("KHARAGPUR"));
            add_at_end(new,convert_string("ROORKEE"));;
        }
        else{
          printf("Invalid number entered ");
          return 0;
        }

  insert_at_beg(&seen,convert_string("game starts"));
   
    int i=0;
   
    while(i<30){
       printf(RED_TEXT"\n          -------------MEMORY GAME: VERBAL MEMORY -----------------          \n\n\n"RESET_TEXT);
      printf(CYAN_TEXT"LIVES :"RESET_TEXT" %d"CYAN_TEXT"            POINTS :"RESET_TEXT" %d  \n\n",lives,points);
     int wor=list_selector();
     int gg;
     
     if((wor==1)||(count_nodes(seen)<2)){
            int new_word=word_select(count_nodes(new));
           gg=1;
            const char* ss=del_at_pos(new,new_word);
            strcpy(games[k],ss);
            k++;
        printf("        WORD :"YELLOW_TEXT" %s\n\n"RESET_TEXT,ss);
            
            
                add_at_end(seen,ss);
           
     }
     
       else if(wor==2){
        int seen_word=word_select(count_nodes(seen));
        gg=2;
        printf("        WORD :"YELLOW_TEXT" %s\n\n"RESET_TEXT,games[seen_word-2]);
        //printf("%s\n",display_at_pos(seen,seen_word));
        
     }
     printf("1."CYAN_TEXT" NEW"RESET_TEXT"             2."CYAN_TEXT" SEEN"RESET_TEXT"              3."CYAN_TEXT" QUIT"RESET_TEXT" \n\nYOUR ANSWER : ");
     
     int user;
     scanf("%d",&user);
     
     
    if(user==gg){
      printf("\e[1;1H\e[2J");// this line clears console 
       //system("cls")  for windows 
      printf("PREVIOUS WORD : CORRECT ANSWER\n");
        points++;
        
    }
    else if(user==3){
      break;
    }
    else if(user!=1 && user!=2 && user!=3){
      printf("Invalid number entered");
      break;
    }
    else{
      if(lives==1){
        printf("\e[1;1H\e[2J");// this line clears console 
         //system("cls")  for windows 
      printf("YOU LOST \n");
      break;
    }
    else{
      printf("\e[1;1H\e[2J");// this line clears console 
       //system("cls")  for windows 
      lives--;
      printf("PREVIOUS WORD : WRONG ANSWER\n");
    }
    }
     
    
    i++;
    
  }
  

  
printf(RED_TEXT"\n          -------------GAME ENDED-----------------          \n\n\n"RESET_TEXT);
  printf(GREEN_TEXT"YOUR FINAL POINTS :"RESET_TEXT" %d",points);
  return 0;
}




 // THIS IS PAIRS MATCHING GAME 



 typedef struct Node {
    int row;
    int col;
     int value;
    struct Node* next;
} Node;

typedef struct SparseMatrix {
    int rows;
    int cols;
    Node** rows_array; 
} SparseMatrix;

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->rows_array = (Node**)malloc(rows * sizeof(Node*));
    for (int i = 0; i < rows; i++) {
        matrix->rows_array[i] = NULL;
    }
    return matrix;
}

void insertElement(SparseMatrix* matrix, int row, int col, int value) {
     
    Node* newNode = createNode(row, col, value);
    newNode->next = matrix->rows_array[row];
    matrix->rows_array[row] = newNode;
}

void printSparseMatrix(SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        Node* curr = matrix->rows_array[i];
        while (curr != NULL) {
            printf("%d \n", curr->value);
            curr = curr->next;
        }
    }
}
void GameBoard(struct SparseMatrix* matrix, int** revealed, int board[10][10]) {
    int zaa=0;
    for (int i = -1; i < matrix->rows; i++) {
        if(i!=-1){
        printf("   %d   ",i);
        }
        else{
            printf("       ");
        }
       
        for (int j = 0; j < matrix->cols; j++) {
            if(zaa==0){
                printf("   %d   ",j);

            }
            else if (revealed[i][j] == 1) {
                struct Node* curr = matrix->rows_array[i];
                
                 printf(CYAN_TEXT"   %d   "RESET_TEXT,board[i][j]);                
            }
            else {
                printf(RED_TEXT"   #   "RESET_TEXT);
            }
        }
        zaa++;
        printf("\n\n");
    }
}

int pairs_matching(){
     int rows = 10;
    int cols = 10;

    struct SparseMatrix* matrix = createSparseMatrix(rows, cols);
    printf(RED_TEXT"\n          ------------- MEMORY GAME : PAIRS MATCHING -----------------          \n\n\n"RESET_TEXT);
printf(GREEN_TEXT"             CHOOSE GAME MODE             \n\n");
printf(RESET_TEXT"1."CYAN_TEXT" EASY\n");
printf(RESET_TEXT"2."CYAN_TEXT" MEDIUM\n");
printf(RESET_TEXT"3."CYAN_TEXT" DIFFICULT\n");

int modee;
int board[10][10];
scanf("%d",&modee);
if(modee==3){
     int board34[10][10] = 
       {
        
        {7,10,11,4,8,3,10,16,13,14},
       {7,11,5,7,6,9,2,12,10,15},
       {8,3,15,1,12,1,2,6,12,9},
        {7,1,3,10,4,7,3,5,13,15},
        {6,11,5,9,3,12,16,9,1,16},
        {1,8,12,1,4,15,5,6,16,14},
        {2,14,2,10,4,11,14,4,2,13},
        {1,8,7,11,13,14,8,2,9,16},
        {15,4,14,6,13,11,10,2,12,13},
         {8,6,2,15,1,5,16,3,5,9},
        
        };
            for (int idf = 0; idf < 10; idf++) {
        for (int jk = 0; jk < 10; jk++) 
            {
               board[idf][jk] = board34[idf][jk];
            }
        
    }
        }
if(modee==2){
     int board1[10][10] = 
       {{1,8,7,11,13,14,8,2,9,16},
        {7,10,11,4,8,3,10,16,13,14},
        {8,3,15,1,12,1,2,6,12,9},
        {2,14,2,10,4,11,14,4,2,13},
        {7,11,5,7,6,9,2,12,10,15},
        {8,6,2,15,1,5,16,3,5,9},
        {1,8,12,1,4,15,5,6,16,14},
        {15,4,14,6,13,11,10,2,12,13},
        {6,11,5,9,3,12,16,9,1,16},
        {7,1,3,10,4,7,3,5,13,15}
        };
            for (int idf = 0; idf < 10; idf++) {
        for (int jk = 0; jk < 10; jk++) 
            {
               board[idf][jk] = board1[idf][jk];
            }
        
    }
        }
        if(modee==1){
        int board2[10][10]=
        {{1,2,3,4,5,4,4,6,7,8},
        {8,3,2,2,9,8,8,4,10,7},
        {9,3,10,8,6,4,3,9,3,3},
        {9,10,3,1,10,4,2,2,2,5},
        {7,10,3,3,1,6,5,1,4,4},
        {7,8,5,10,9,8,6,1,6,9},
        {10,6,6,8,1,4,8,2,2,2},
        {2,10,5,1,5,1,4,3,6,8},
        {10,7,6,7,9,6,1,5,9,5},
        {7,10,7,7,9,7,1,5,9,5} };
           for (int idf = 0; idf < 10; idf++) {
        for (int jk = 0; jk < 10; jk++) 
            {
               board[idf][jk] = board2[idf][jk];
            }

        }
        

    int** revealed = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        revealed[i] = (int*)malloc(cols * sizeof(int));
        if (!revealed[i]) {
            return 0; 
        }
        for (int j = 0; j < cols; j++) {
            revealed[i][j] = 0;  
        }
    }

    int totalPairs = (rows*cols)/2;
    int pairsmatched = 0;

    while (1) {

           printf(RED_TEXT"\n          ------------- MEMORY GAME : PAIRS MATCHING -----------------          \n\n\n"RESET_TEXT);

        GameBoard(matrix,revealed,board);

        if (pairsmatched == totalPairs) {
            printf("\nYOU WON THE GAME \n");
            break;
        }

        int row1, col1, row2, col2;

        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        if (row1 < 0 || row1 >= rows || col1 < 0 || col1 >= cols || revealed[row1][col1] == 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        revealed[row1][col1] = 1;
        GameBoard(matrix,revealed,board);

        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &row2, &col2);
        if (row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols || revealed[row2][col2] == 1) {
            printf("Invalid input. Please try again.\n");
            revealed[row1][col1] = 0; 
            continue;
        }

        revealed[row2][col2] = 1;
        GameBoard(matrix,revealed,board);

        if (board[row1][col1] == board[row2][col2]) {
            printf("You've found a pair!\n");
            pairsmatched++;
        } else {
            printf("Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
            sleep(3);
                printf("\e[1;1H\e[2J");// this line clears console 
                 //system("cls")  for windows 

            printf("Try again.\n");
        }
    }

    for (int i = 0; i < rows; i++) {
        free(revealed[i]);
    }
    free(revealed);

    return 0;
}
return 0;
}


int main(){
  printf(RED_TEXT"\n          ------------- MEMORY GAME -----------------          \n\n\n"RESET_TEXT);
  printf(GREEN_TEXT"        CHOOSE GAME TYPE             \n\n\n");
  printf(RESET_TEXT"1."CYAN_TEXT" Verbal memory\n\n");
  printf(RESET_TEXT"2."CYAN_TEXT" Visual memory\n\n"RESET_TEXT);
  printf("Choice : ");


  int gameplay;
  scanf("%d",&gameplay);
    printf("\e[1;1H\e[2J");// this line clears console 
     //system("cls")  for windows 
  if(gameplay==1){
    verbal_memory();
  }
  else if(gameplay==2){
    pairs_matching();
  }
  else{
    printf("Invalid number entered");
    return 0;
  }
  return 0; 

}