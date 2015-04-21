template <class T> class IQueue { 
public:    
    // добавить в хвост    
    virtual void put(const T& elem) = 0;    
    // взять из головы    
    virtual T take() = 0;    
    // получить элемент по номеру 0...size-1,     
    // 0 это голова, size-1 это хвост    
    virtual T get(int i) const = 0;    
    // узнать размер очереди    
    virtual int size() const = 0; 
}; 

template <class T> class ISet { 
public:    
    // добавить элемент    
    virtual void add(const T& elem) = 0;    
    // удалить элемент    
    virtual void remove(const T& elem) = 0;    
    // содержится ли элемент    
    virtual bool contains(const T& elem)  = 0;
    // узнать размер множества    
    virtual int size() const = 0; 
}; 
