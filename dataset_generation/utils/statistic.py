import re
import tiktoken
import matplotlib.pyplot as plt
import pandas as pd
from datasets import load_dataset

def remove_fortran_comments(code):
    """
    Remove comments from the  origianl Fortran code.
    it is only for token statistic as it is not accurate. 
    
    arg:
    code (str): Orginal Fortran Code Str

    return:
    str: Fortran Code Str without comments
    """
    code_no_comments = []
    for line in code.splitlines():
        line = re.split(r'!', line)[0]
        if not re.match(r'^\s*[cC*]', line):
            code_no_comments.append(line)
    
    return '\n'.join(code_no_comments)

def count_tokens(code):
        encoding = tiktoken.encoding_for_model("gpt-4")
        token_count = len(encoding.encode(code + "\n",disallowed_special=()))
        return token_count

def analyze_token_distribution(tokens_list, token_threshold):
    """
    Analysis token distribution

    arg:
    tokens_list (list): List contains all data entries tokens 
    token_threshold (int)

    return:
    int: The amount of data entries (The numbere of tokens < token_threshold)
    plt.Figure: token distribution figure。
    """
    df = pd.DataFrame(tokens_list, columns=['tokens'])

    entries_less_than_threshold = df[df['tokens'] < token_threshold].shape[0]

    plt.figure(figsize=(10, 6))
    plt.hist(df['tokens'], bins=50, edgecolor='black', alpha=0.7)
    plt.axvline(token_threshold, color='red', linestyle='dashed', linewidth=1)
    plt.text(token_threshold, plt.ylim()[1] * 0.9, f'{token_threshold} tokens', color='red', ha='center')

    plt.title('Token Distribution in Data Entries')
    plt.xlabel('Number of Tokens')
    plt.ylabel('Frequency')

    fig = plt.gcf()

    return entries_less_than_threshold, fig

# main
if __name__ == "__main__":
    Fortran_dataset = load_dataset("codeparrot/github-code", "FORTRAN-all")
    data = Fortran_dataset["train"][0:85000]

    # Remove comments and Get tokens list
    tokens_list = []
    for idx in range(len(data['code'])):
        if idx % 10000 == 0:
            print(f"Working on the {idx}th code...")
        fortran_code = data['code'][idx]
        fortran_code_wo_comment = remove_fortran_comments(fortran_code)
        token_numbers = count_tokens(fortran_code_wo_comment)
        tokens_list.append(token_numbers)
        
    # statistic
    token_threshold = 600
    count, fig = analyze_token_distribution(tokens_list, token_threshold)

    # Show results
    print(f"Number of data entries with tokens less than {token_threshold}: {count}")
    plt.show()
