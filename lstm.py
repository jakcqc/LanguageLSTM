import torch
import torch.nn as nn
import torch.optim as optim
import pandas as pd
import json

# Define the LSTM model
class LSTMModel(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(LSTMModel, self).__init__()
        self.hidden_size = hidden_size
        self.lstm = nn.LSTM(input_size, hidden_size)
        self.fc = nn.Linear(hidden_size, output_size)
    
    def forward(self, input):
        batch_size = input.size(1)
        h0 = torch.zeros(1, batch_size, self.hidden_size).to(input.device)
        c0 = torch.zeros(1, batch_size, self.hidden_size).to(input.device)
        output, (hn, cn) = self.lstm(input, (h0, c0))
        output = self.fc(output[-1])
        return output

# Define the sequence to tensor function
def sequence_to_tensor(sequence):
    # Initialize a tensor of zeros
    tensor = torch.zeros(len(sequence), 1, len(char_to_index))
    # Loop through each character in the sequence
    for i, char in enumerate(sequence):
        # Set the corresponding value in the tensor to 1
        tensor[i][0][char_to_index[char]] = 1
    return tensor

# Load the CSV file and preprocess the data
df = pd.read_csv('sentences.csv')
input_sequences = df['input'].tolist()
target_sequences = df['target'].tolist()

# Create dictionaries to map characters to indices and vice versa
all_chars = set(''.join(input_sequences + target_sequences))
char_to_index = {char: i for i, char in enumerate(all_chars)}
index_to_char = {i: char for i, char in enumerate(all_chars)}

# Define the hyperparameters
input_size = len(char_to_index)
hidden_size = 128
output_size = len(char_to_index)
learning_rate = 0.001
num_epochs = 1
# Initialize the model, loss function, and optimizer
model = LSTMModel(input_size, hidden_size, output_size)
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=learning_rate)

# Train the model
for epoch in range(num_epochs):
    for i in range(len(input_sequences)):
        # Convert the input sequence and target sequence to tensors
        input_tensor = sequence_to_tensor(input_sequences[i])
        target_tensor = torch.tensor([char_to_index[char] for char in target_sequences[i]]).unsqueeze(1)
        
        # Forward pass
        output_tensor = model(input_tensor)
        loss = criterion(output_tensor, target_tensor)
        
        # Backward and optimize
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
    # Print the loss for every 100 epochs
    if (epoch+1) % 5 == 0:
        print('Epoch [{}/{}], Loss: {:.4f}'.format(epoch+1, num_epochs, loss.item()))

# Generate a sequence from a given input sequence
def generate_sequence(input_sequence):
    # Set the model to evaluation mode
    model.eval()
    
    # Convert the input sequence to a tensor
    input_tensor = sequence_to_tensor(input_sequence)
    
    # Generate the output sequence
    with torch.no_grad():
        output_tensor = model(input_tensor)
        output_sequence = ''
        for i in range(output_tensor.size(0)):
            top_index = output_tensor[i].argmax()
            output_char = index_to_char[top_index.item()]
            output_sequence += output_char
            
    return output_sequence

# Generate the output sequence
output = generate_sequence(" object o1 with rotation 0-0-0 to 360-360-360 and position on W - in O2 and material green - yellow")
