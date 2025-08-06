const express = require('express');
const app = express();

// Middleware
app.use(express.json()); // Fix: add parentheses

// Store items in memory
let items = []; // Add: initialize items array

class TodoManager {
    constructor() {
        this.currentId = 1;
    }

    // Add item
    addItem(task, status) {
        const item = {
            id: this.currentId++,
            task,
            status,
            createdAt: new Date()
        };
        items.push(item);
        return item;
    }

    // Get all items
    getAllItems() {
        return items;
    }

    // Update item
    updateItem(id, updates) {
        const itemIndex = items.findIndex(item => item.id === id);
        if (itemIndex !== -1) {
            items[itemIndex] = { ...items[itemIndex], ...updates };
            return items[itemIndex];
        }
        return null;
    }

    // Delete item
    deleteItem(id) {
        const initialLength = items.length;
        items = items.filter(item => item.id !== id);
        return initialLength !== items.length;
    }
}

// Create TodoManager instance
const todoManager = new TodoManager();

// Routes
app.get('/todos', (req, res) => {
    res.json(todoManager.getAllItems());
});

app.post('/todos', (req, res) => {
    const { task, status } = req.body;
    
    // Validation
    if (!task) {
        return res.status(400).json({ error: "Task is required" });
    }

    const newItem = todoManager.addItem(task, status || 'pending');
    res.status(201).json(newItem);
});

app.put('/todos/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const updatedItem = todoManager.updateItem(id, req.body);
    
    if (updatedItem) {
        res.json(updatedItem);
    } else {
        res.status(404).json({ error: "Item not found" });
    }
});

app.delete('/todos/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const deleted = todoManager.deleteItem(id);
    
    if (deleted) {
        res.json({ message: "Item deleted" });
    } else {
        res.status(404).json({ error: "Item not found" });
    }
});

// Start server
app.listen(3000, () => {
    console.log('Server running on port 3000');
});
