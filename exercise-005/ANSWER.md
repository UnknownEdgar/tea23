# Aufgabe 5 – Vergleich: Verkettete Liste vs. Mini-Vector

## Vorteile der verketteten Liste

- **Effiziente Einfügungen/Löschungen**: O(1) wenn der Knoten bekannt ist
- **Keine Umallokation**: Wächst ohne Speicher zu verschwenden
- **Flexible Größe**: Kann beliebig groß wachsen ohne Reservierung
- **Speichereffizient bei vielen Löschungen**: Keine Fragmentierung wie bei dynamischen Arrays
- **Cache-unabhängig**: Keine Performance-Probleme durch Speicher-Neuallokation

## Nachteile der verketteten Liste

- **Langsamer Random Access**: O(n) zum Zugriff auf ein Element nach Index
- **Speicher-Overhead**: Jeder Knoten benötigt einen zusätzlichen Zeiger (8 Bytes auf 64-bit)
- **Cache-unfriendly**: Knoten sind über den Speicher verteilt → schlechte CPU-Cache-Nutzung
- **Komplexere Implementierung**: Mehr Code, mehr Fehlerquellen
- **Speicherfragmentierung**: Viele kleine Heap-Allokationen

## Vorteile des Mini-Vectors

- **Schneller Random Access**: O(1) Zugriff auf ein Element nach Index
- **Cache-friendly**: Kontinuierlicher Speicher → bessere CPU-Cache-Nutzung
- **Speichereffizient**: Kein Overhead durch Zeiger
- **Einfachere Implementierung**: Unkompliziert zu verstehen und zu debuggen
- **Schnelle Iteration**: Durchlaufen ist sehr schnell

## Nachteile des Mini-Vectors

- **Teure Einfügungen am Anfang**: O(n) weil alle Elemente verschoben werden
- **Speicherverschwendung**: Wenn die Kapazität > Size ist
- **Umallokation**: Teuer bei Kapazitätserweiterung (O(n))
- **Einfügungen am Anfang/Mitte sind langsam**: Erfordern Verschiebung aller nachfolgenden Elemente
- **Speicher-Overhead bei Wachstum**: Verdoppelung führt zu temporär doppeltem Speicher

## Wann benutzt man welche Struktur?

### Verkettete Liste verwenden, wenn:
- Häufige Einfügungen/Löschungen am Anfang oder in der Mitte
- Die Größe nicht im Voraus bekannt ist
- Speicher-Allokation möglicherweise teuer ist
- Beispiele: LRU-Cache, Task-Queues, Undo/Redo-Stacks

### Mini-Vector verwenden, wenn:
- Häufiger Random Access erforderlich ist
- Meist am Ende eingefügt wird (push_back)
- Performance-kritische Anwendungen
- Cache-Lokalität wichtig ist
- Beispiele: Dynamic Arrays, Matrices, Particle Systems, Audio Buffers

## Was passiert, wenn man die Elemente sortiert?

### Beim Mini-Vector:
- **Sortieren ist relativ einfach**: Kann QuickSort, MergeSort etc. verwenden
- **Performance**: O(n log n) mit guten Cache-Eigenschaften
- **Nach dem Sortieren**: Die Datenlokalität bleibt erhalten
- **Binäre Suche möglich**: O(log n) auf sortierten Daten

### Bei der Liste:
- **Sortieren ist kompliziert**: QuickSort funktioniert nicht gut (kein Random Access)
- **MergeSort ist ideal**: O(n log n), funktioniert gut mit Listen
- **Nach dem Sortieren**: Muss die Zeiger-Struktur komplett neu aufgebaut werden
- **Binäre Suche nicht möglich**: Kein effizienter Random Access
- **Beispiel-Algorithmen**:
  - Insertion Sort: O(n²) aber einfach implementierbar
  - Merge Sort: O(n log n) und optimal für Listen

## Wie würden Sie einen Binären Baum strukturieren?

Ein binärer Baum hätte folgende Struktur:

```cpp
typedef struct TreeNode {
    unsigned int data;
    struct TreeNode* pLeft;   // Zeiger auf linkes Kind
    struct TreeNode* pRight;  // Zeiger auf rechtes Kind
} TreeNode_t;

typedef struct BinaryTree {
    TreeNode_t* pRoot;        // Wurzel des Baums
    unsigned int size;        // Anzahl der Knoten
} BinaryTree_t;
```

**Wichtige Operationen:**
- `insert()`: Neuen Knoten einfügen (abhängig von BST-Eigenschaft)
- `search()`: Knoten suchen (O(log n) bei ausgeglichenem Baum)
- `delete()`: Knoten entfernen (komplex, verschiedene Fälle)
- `traverse()`: Tiefensuche (in-order, pre-order, post-order) oder Breitensuche

**Beispiel: Binärer Suchbaum (BST)**
```
        50
       /  \
      30   70
     / \   / \
    20 40 60 80
```

**Speicher-Layout**: Wie bei der Liste – Knoten sind auf dem Heap verteilt, verbunden durch Zeiger.

**Vergleich mit Vector/Liste:**
- **Vorteile**: Schnelle Suche (O(log n)), flexibles Wachstum
- **Nachteile**: Cache-unfriendly, komplexe Verwaltung, schlechtere Lokalität als Vector