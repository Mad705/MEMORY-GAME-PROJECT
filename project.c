#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
        char data[20];
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
int main(){
  int points =0,lives=3;
    node* new = (node*)malloc(sizeof(node));
     node* seen = (node*)malloc(sizeof(node));
     char games[11][20];
     int k=0;
     
    new=NULL;
     seen=NULL;
    
    // Madhu is a bhosdi magga 
    insert_at_beg(&new,convert_string("begin"));
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
    

  insert_at_beg(&seen,convert_string("game starts"));
   
    int i=0;
   
    while(i<20){
      printf("LIVES : %d            POINTS : %d  \n\n",lives,points);
     int wor=list_selector();
     int gg;
     
     if((wor==1)||(count_nodes(seen)<2)){
            int new_word=word_select(count_nodes(new));
           gg=1;
            const char* ss=del_at_pos(new,new_word);
            strcpy(games[k],ss);
            k++;
        printf("        WORD : %s\n\n",ss);
            
            
                add_at_end(seen,ss);
            
     }
     
       else if(wor==2){
        int seen_word=word_select(count_nodes(seen));
        gg=2;
        printf("        WORD : %s\n\n",games[seen_word-2]);
        //printf("%s\n",display_at_pos(seen,seen_word));
        
     }
     printf("1. NEW             2. SEEN \n\nYOUR ANSWER : ");
     
     int user;
     scanf("%d",&user);
    if(user==gg){
      printf("PREVIOUS WORD : CORRECT ANSWER\n");
        points++;
    }
    else{
      if(lives==1){
      printf("YOU LOST \n");
      break;
    }
    else{
      lives--;
      printf("PREVIOUS WORD : WRONG ANSWER\n");
    }
    }
     
    
    i++;
  }
  

  
  printf("GAME ENDED ");
  printf("YOUR FINAL POINTS : %d",points);
}

