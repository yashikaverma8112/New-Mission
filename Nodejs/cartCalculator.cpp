const calculateCart = (items) => {
    let subtotal = 0;
    
    // Print each item
    items.forEach(item => {
        console.log(`Item: ${item.name}, Price: ${item.price}, Quantity: ${item.quantity}`);
        subtotal += item.price * item.quantity;
    });
    
    const tax = subtotal * 0.1;
    const total = subtotal + tax;
    
    return {
        subtotal,
        tax,
        total
    };
};

// Test data
const cartItems = [
    { name: "T-shirt", price: 15.99, quantity: 2 },
    { name: "Jeans", price: 29.99, quantity: 1 }
];

const cartSummary = calculateCart(cartItems);
console.log("\nCart Summary:");
console.log(`Subtotal: ${cartSummary.subtotal.toFixed(2)}`);
console.log(`Tax: ${cartSummary.tax.toFixed(2)}`);
console.log(`Total: ${cartSummary.total.toFixed(2)}`);
