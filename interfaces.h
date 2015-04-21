template <class T> class IQueue { 
public:    
    // �������� � �����    
    virtual void put(const T& elem) = 0;    
    // ����� �� ������    
    virtual T take() = 0;    
    // �������� ������� �� ������ 0...size-1,     
    // 0 ��� ������, size-1 ��� �����    
    virtual T get(int i) const = 0;    
    // ������ ������ �������    
    virtual int size() const = 0; 
}; 

template <class T> class ISet { 
public:    
    // �������� �������    
    virtual void add(const T& elem) = 0;    
    // ������� �������    
    virtual void remove(const T& elem) = 0;    
    // ���������� �� �������    
    virtual bool contains(const T& elem)  = 0;
    // ������ ������ ���������    
    virtual int size() const = 0; 
}; 
