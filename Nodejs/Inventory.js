class Inventory{
    constructor(){
        this.items=[];
    }
    
    addItem(product, stock){
        
        if(!product.name || !product.price || stock < 0){
            throw new Error("Invalid")
        }
        
        this.items.push({...product,stock});
    }
    
    removeProduct(product){
        this.items = this.items.filter(item=>item.name!= product);
    }
    
    updateStock(product,newStock){
        const item = this.items.find(item=>item.name === product);
        if(item){
            item.stock = newStock;
        }
        else{
            throw new Error("Product not found");
        }
    }
    getInventory(){
        return this.items;
    }
}

try{
    const inventory = new Inventory();
    
    inventory.addItem({ name: "Laptop", price: 999.99 }, 10);
    inventory.addItem({ name: "Mouse", price: 29.99 }, 20);

    // Show current inventory
    console.log("Current Inventory:", inventory.getInventory());
    inventory.updateStock("Laptop", 15);
    console.log("\nAfter updating Laptop stock:", inventory.getInventory());

    // Remove product
    inventory.removeProduct("Mouse");
    console.log("\nAfter removing Mouse:", inventory.getInventory());
}
catch(error){
    console.log(error);
}
