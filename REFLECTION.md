# АТД "Множество" на основе кода BST

## 1. *Какие функции войдут в публичный интерфейс множества, а какие останутся деталями реализации? Правда ли они могут иметь другое название?*

### Функции, которые войдут в интерфейс:
```BST* newBst(void)```

```void bstInsert(BST* tree, int value)```

```bool bstContains(BST* tree, int value)```

```void bstDelete(BST* tree, int value)```

```void bstFree(BST* tree)```

```int bstSize(BST* tree)```

```Iterator* iteratorInit(BST* tree)```

```bool iteratorHasNext(Iterator* it)```

```int iteratorNext(Iterator* it)```

```void iteratorFree(Iterator* it)```

### Функции, оставшиеся деталями реализации:
```static void freeNode(Node* node)```

Так как мы уже имеем не АТД BST, а множество, реализация которого происходит через BST, функции нам тоже можно переименовывать, например, с **bst..** на **set..**

## 2. *Какие из написанных вами функций не имеют смысла в интерфейсе множества?*

```void bstInorder(BST* tree)```

```static void bstInorderNode(Node* node)```

```void bstPreorder(BST* tree)```

```static void bstPreorderNode(Node* node)```

```void bstPostorder(BST* tree)```

```static void bstPostorderNode(Node* node)```

```int bstHeight(BST* tree)```

```int bstSize(BST* tree)```

```bool bstMin(BST* tree, int* val)```

```bool bstMax(BST* tree, int* val)```

```BST* bstMerge(BST* tree1, BST* tree2)```

```bool bstIsValid(BST* tree)```

```bool bstMinKth(BST* tree, int* val, int k)```

## 3. *Что нужно изменить, чтобы можно было безболезненно заменить BST на другую реализацию (например, хеш-таблицу), не меняя код, который использует множество?*

Во-первых, нужно спрятать реализацию структуры от пользователя в **.c**

Во-вторых, переименовать все функции, чтобы не было следов **bst**

В-третьих, избавться от всех сппецифичных **bst** функций
