from transformers import MarianMTModel, MarianTokenizer
# Load the pre-trained translation model
model_name = 'Helsinki-NLP/opus-mt-en-vi'
model = MarianMTModel.from_pretrained(model_name)
tokenizer = MarianTokenizer.from_pretrained(model_name)

# Text to be translated
text = "Hello, how are you?"

# Tokenize the text
input_ids = tokenizer.encode(text, add_special_tokens=True, return_tensors='pt')

# Translate the input
translated = model.generate(input_ids)

# Decode the translated output
translated_text = tokenizer.decode(translated[0], skip_special_tokens=True)

# Print the translated text
print(translated_text)