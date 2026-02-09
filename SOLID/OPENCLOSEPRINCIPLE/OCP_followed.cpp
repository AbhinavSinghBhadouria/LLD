#include<iostream>
#include<vector>

using namespace std;
class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
        this->name= name;
        this->price= price;
    }
};

class ShoppingCart{
    private:
    vector<Product*> products;

    public:
    void addProduct(Product* p){
        products.push_back(p);
    }

     const vector<Product*>& getProducts(){
        return products;

    }
    double calculateTotal(){
        double total= 0;
        for(auto p: products){
            total+= p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Shopping Cart Invoice:"<<endl;
        for(auto p: cart->getProducts()){
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<< cart->calculateTotal()<<endl;
}
};


// Abstract class for shopping cart storage
class Persistance{
    private:
    ShoppingCart* cart;
    public:
    virtual void save(ShoppingCart* cart) = 0; // pure virtual function
};

class SQLPersistance: public Persistance{
    // @override
    void save(ShoppingCart* cart)override{
        cout<<"Saving shopping cart to SQL database..."<<endl;
        // code to save cart data to SQL database
    }
};

class MongoPersistance: public Persistance{
    void save(ShoppingCart* cart)override{
        cout<<"Saving shopping cart to NoSQL database..."<<endl;
        // code to save cart data to NoSQL database
    }
};
class FilePersistance: public Persistance{
    void save(ShoppingCart* cart)override{
        cout<<"Saving shopping cart to file..."<<endl;
        // code to save cart data to file
    }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Headphones", 199.99));

    ShoppingCartPrinter printer(cart);
    printer.printInvoice();

    Persistance* db = new SQLPersistance();
    Persistance* sqlp = new MongoPersistance();
    Persistance* file = new FilePersistance();

    db->save(cart);
    sqlp->save(cart);
    file->save(cart);
    return 0;
}