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

class ShoppingCartStorage{
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
        // code to save cart data to database
    }

    void saveToNoSQLDatabase(){
        cout<<"Saving shopping cart to NoSQL database..."<<endl;
        // code to save cart data to NoSQL database
    }

    void saveToFile(){
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

    ShoppingCartStorage storage(cart);
    storage.saveToSQLDatabase();
    storage.saveToNoSQLDatabase();
    storage.saveToFile();

    return 0;
}