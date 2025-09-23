#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// A court of thorns and roses
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
// TBR : 안읽은 책 -> None, 0: hate, 10 : love it, None : I haven't read
// *중복 존재, 모든 책은 선반에 넣어놓고 있어야함.
// *무조건 보존해야하는 것 : 가장 좋아하는 책(highest ranking)과 TBR은 무조건 보존
// 삭제 : 가장 싫어하는 책(smallest rank)과 중복 삭제, 
// 삭제 : 삭제하는 책과 같은 랭크를 가지고 있는 책들 삭제 *** 
// 삭제 : !무조건 보존을 제외하고는 삭제 가능!

int cur_book_count = 0; // 현재 선반에 있는 책들! (새롭게 추가한 책들 제외)
int rank_book_count = 0; // 가지고 있는 것 중 읽어본 책들의 수
int none_book_count = 0; // 가지고 있는 것 중 아직 안읽어본 책 숫자

// 문자열 뒤에 None 삭제
void Remove_All_None(char *s, const char *sub) {
    size_t m = strlen(sub);
    if (m == 0) return;
    char *p;
    while ((p = strstr(s, sub)) != NULL) {
        memmove(p-1, p + m, strlen(p + m) + 1);
    }
}

int max_val = 0; // 내가 갖고 있는 책 중에서 가장 높은 숫자

// 문자열 뒤에 붙어 있는 Num
void Remove_Num(char *s) {
    int len = strlen(s);

    char cur_char = s[len-1];
    // 가장 높은 rank 찾기
    if('0'<=cur_char && cur_char<='9')
        if(max_val<s[len-1]-'0') max_val = s[len-1]-'0';

    // 숫자 제거
    // 로직 : HI_9 이면 '_' 위치에 '\0'을 삽입해 제거하기
    if('1'<=s[len-1] && s[len-1]<='9'){
        s[len-2] = '\0';
    }
}

// 중복을 삭제하고 나서도 공간이 부족하면, 랭크가 가장 낮은 문자열과 그와 같은 문자열 삭제
int Remove_Same_Rank(char **books, int size_array, int insufficient_num, int b, int *rank) {
    // 제거한 문장과 같은 랭킹 제거
    int left_count = insufficient_num;

    // 0 ~ max_val 까지 탐색하면서 같은 rank인 모든 문자열 삭제
    for(int k=0; k<max_val && k<9; k++){
        if(k>=max_val) continue; // 가장 큰 rank인 경우는 제외
        int cur_num = k;
        // 순회하면서 삭제
        for(int i=none_book_count+b; i<size_array; i++){
            if(cur_num == rank[i-none_book_count-b]) {
                cur_book_count-=1;
                rank_book_count-=1;
                --left_count;
            }
        }
        // 더 이상 공간이 부족하지 않으면 break
        if(left_count<=0) break;
    }
    return left_count;
}

// 중복을 삭제
void Remove_Dup_St(char **books, int size_array, int *b) {
    // minus는 책을 하나 삭제할 때마다 즉각적으로 반영하기 위한 변수
    // ex) 책이 10개 있었다면 하나 삭제하면 minus++ 을 한 후, 10-minus = 9으로 전체 책의 갯수 반영.
    int minus = 0;
    
    // 순회하며 삭제
    for(int i=0; i<size_array-1-minus; i++){
        for(int j=i+1; j<size_array-minus; j++){
            if(strcmp(books[i],books[j])==0){
                cur_book_count--;
                
                // 여기 로직이 만약 새로운 책으로 Hi 9와 기존에 책에도 Hi 9가 있다면 
                // 기존 책과 새로운 책을 합칠 때 b을 1을 감소한다.
                if(j<none_book_count + *b)
                    none_book_count--;
                else{
                    if(i<*b){
                        *b-=1;
                    }
                    rank_book_count--;
                }
                // 삭제
                for(int k=j; k<size_array-1-minus; k++){
                    books[k] = books[k+1];
                }
                minus++;
            }
        }
    }
}

// 
void Sort_String(char **books, int size_array)
{
    char *tmpBooks;

    // 아스키코드를 기준으로 내림차순
    for(int i=0; i<size_array-1; i++){
        for(int j=i+1; j<size_array; j++){
            if(books[i][strlen(books[i])-1] <  books[j][strlen(books[j])-1]){
                tmpBooks = books[i];
                books[i] = books[j];
                books[j] = tmpBooks;
            }
        }
        // 마지막 char에 숫자라면은 rank_book_count++, else none_book_count++
        if('0' <= books[i][strlen(books[i])-1] && books[i][strlen(books[i])-1]<='9') rank_book_count++;
        else none_book_count++;
    }
    // 마지막 문자열도 검사 (위에 for문에는 size_array-1이니깐)
    if('0' <= books[size_array-1][strlen(books[size_array-1])-1] && books[size_array-1][strlen(books[size_array-1])-1] <='9') rank_book_count++;
}

// 알파벳 순으로 정렬
void Sorting_Again(char **books, int size_array)
{
    char *tmpBooks;
    
    for(int i=0; i<size_array-1; i++){
        for(int j=i+1; j<size_array; j++){
            if(strcmp(books[i],books[j])>0){
                tmpBooks = books[i];
                books[i] = books[j];
                books[j] = tmpBooks;
            }
        }
    }
}

int main()
{
    int b;
    int index = 0;
    int cur_index = 0;

    // books 에 새로 넣을 책만 넣기
    scanf("%d", &b); fgetc(stdin); // 남은 버퍼를 비움
    char **books = (char**)malloc((size_t)b * sizeof *books);
    for (int i = 0; i < b; i++) {
        char title[1025] = ""; 
        scanf("%[^\n]", title); fgetc(stdin);
        char *copy = strdup(title);
        books[index++] = copy;
    }

    // cur_books에 이미 갖고 있는 책만 넣기
    int n;
    scanf("%d", &n); fgetc(stdin);
    books = (char**)realloc(books,(size_t)(b+n) * sizeof *books);
    char **cur_books = (char**)malloc((size_t)n * sizeof *books);
    for (int i = 0; i < n; i++) {
        char name[1025] = "";
        scanf("%[^\n]", name); fgetc(stdin);
        char *copy = strdup(name);
        cur_books[cur_index++] = copy;
    }

    int rank[n]; // 읽었던 책 중 등급(rank) 저장
    int rank_index = 0;

    cur_book_count = n; // 현재 가지고 있는 책 수 저장

    // rank와 None을 기반으로 정렬 --> 아스키코드 기준으로 None이 가장 위, 낮은 숫자가 가장 밑으로 내림차순
    Sort_String(cur_books,cur_book_count);

    // 기존 책의 num, None, 빈 칸 제거
    for(int i=0; i<n; i++){
        // 끝에 숫자 저장
        if('0' <= cur_books[i][strlen(cur_books[i])-1] && cur_books[i][strlen(cur_books[i])-1] <= '9'){
            rank[rank_index++] = cur_books[i][strlen(cur_books[i])-1] - '0';
        }
        // 끝에 숫자 저장
        Remove_Num(cur_books[i]);
        // 끝에 None 제거
        Remove_All_None(cur_books[i], "None");
    }

    // 기존 책과 새로운 책 합치기 (cur_books + books)
    books = (char**)realloc(books,(size_t)(b+n) * sizeof *books);
    for(int i=b; i<b+cur_book_count; i++){
        char *copy = strdup(cur_books[i-b]);
        books[i] = copy;
    }

    // 중복되는 책 삭제
    Remove_Dup_St(books,b+cur_book_count, &b);

    // 부족한 책장 공간 계산
    int insufficient_num = n - (cur_book_count+b);
    // 최종으로 부족한 책장 공간 계산
    int final_insuff_num;
    
    // 부족하다면 읽었던 책 중에서 가장 높은 랭크를 제외하고 삭제하기
    if(insufficient_num<0){
        final_insuff_num = Remove_Same_Rank(books, cur_book_count + b, abs(insufficient_num),b, rank);
    }

    // 모든 책을 알파벳순으로 정렬
    Sorting_Again(books,cur_book_count+b);

    if(final_insuff_num > 0) { // final_insuff_num >0 : 아직도 부족하다
        printf("Your TBR is out of control Clara!\n");
    }
    else{ // final_insuff_num <=0 : 더 이상 부족하지 않다
        for(int i=0; i<cur_book_count+b; i++){
            printf("%s\n", books[i]);
        }
    }

    // // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // // To debug: fprintf(stderr, "Debug messages...\n");
    free(books);
    free(cur_books);

    return 0;
}
