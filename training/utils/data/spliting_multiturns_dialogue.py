import json

def split_conversations_on_assistant(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as f:
        data = json.load(f)

    new_data = []

    for item in data:
        conversation_id = item['id']
        messages = item['messages']

        current_conversation = []

        for message in messages:
            current_conversation.append(message)
            
            if message['role'] == 'assistant':
                new_data.append({
                    "id": conversation_id,
                    "messages": current_conversation[:]
                })

    with open(output_file, 'w', encoding='utf-8') as f:
        json.dump(new_data, f, ensure_ascii=False, indent=4)

# Test the function
input_file = '/home/uconn/BinLei/F2C-Translator/data/F2C_dialogue_2.5K_v2_0_20.json'  
output_file = '/home/uconn/BinLei/F2C-Translator/data/F2C_dialogue_2.5K_v2_0_20_test.json'  
split_conversations_on_assistant(input_file, output_file)
