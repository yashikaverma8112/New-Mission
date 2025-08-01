class ShoppingCart{
    constructor(){
        this.items=[];
    }
    
    addItem(product,quantity){
        this.items.push({
            ...product,
            quantity
        });
    }
    
    calculatePrice(){
        return this.items.reduce((total,item)=>{
            return total + (item.price*item.quantity);
        },0);
    }
    
    getItemCount(){
        return this.items.reduce((count,item)=>{
            return count + item.quantity;
        },0);
    }
    
    getSummary(){
        return{
            items:this.items,
            totalItems:this.getItemCount(),
            totalPrice:this.calculatePrice()
        };
    }
}

const cart = new ShoppingCart();
cart.addItem({ name: "T-shirt", price: 15.99 }, 2);
cart.addItem({ name: "Jeans", price: 29.99 }, 1);

// Get cart summary
const summary = cart.getSummary();
console.log("Cart Summary:", summary);
