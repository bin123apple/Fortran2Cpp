#include <iostream>
#include <functional>

class BaseT {
public:
    int i = 0;
    
    BaseT() {}

    virtual void writeI() const {
        baseWriteI();
    }

    virtual void writeProcPtr() const {
        baseWriteI();
    }

protected:
    void baseWriteI() const {
        std::cout << "Base write_i: " << i << std::endl;
    }
};

class T : public BaseT {
public:
    T() : BaseT() {}

    void writeI() const override {
        baseWriteI();
    }

    void writeProcPtr() const override {
        std::cout << "Extended write_i: " << i << std::endl;
    }
};

int main() {
    T obj_ext;
    obj_ext.i = 3;
    obj_ext.writeI();
    obj_ext.writeProcPtr();

    BaseT* obj = new T();
    obj->i = 5;
    obj->writeI();
    obj->writeProcPtr();

    delete obj;

    return 0;
}