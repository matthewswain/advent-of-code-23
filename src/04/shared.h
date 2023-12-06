void shiftString(char* s, int len);
int takeNumber(char* s);
void takeSpace(char* s);

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* newNode(int value);
void freeNode(Node* n);
Node* addNode(Node* existing, Node* add);
int countMatches(Node* a, Node* b);
int matchesOnCard(char* line);
int countLines(char* c);
