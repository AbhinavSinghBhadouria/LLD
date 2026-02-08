#include<iostream>
#include<vector>

using namespace std;
// product class representing any item of any Ecommerce website
class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};
// Violating SRP: shopping cart is handling multiple responsibilities in a single method or we can say that the function


class ShoppingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    //1. calculate tptal price in cart
    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }

    //2. print invoice
    void printInvoice(){
        cout<<"shopping cart invoice:"<<endl;
        for(auto p: products){
            cout<<p->name << " -$"<< p->price<<endl;
        }

        cout<<"Total: $"<< calculateTotal()<<endl;
    }


    //3. violating srp- save to db
    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
        // code to save cart data to database
    }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Headphones",200));
    cart->printInvoice();
    cart->saveToDatabase();
    delete cart;
    return 0;
}