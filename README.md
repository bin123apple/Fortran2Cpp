# F2C-Translator

## Introduction
Fortran has been a widely used programming language for scientific computation since 1957. With technological advancements, modern languages like C++ have become preferable for some projects due to their greater flexibility and features. However, the lack of an accurate and comprehensive Fortran-to-C++ translation dataset means that existing large models, including GPT-4, often struggle to perform this task effectively, resulting in translations that may fail to compile or pass unit tests. F2C-Translator aims to address this issue.

## Model
The Model is avaliable on Huggingface: [F2C-Translator](https://huggingface.co/Bin12345/F2C-Translator)

**NOTE:** We are still training the model. We will continue to update the F2C-Translator.

## Evaluation
We compared with various models (WizardCoder-15B-V1.0, CodeLlama-13b-Instruct-hf, starcoder, Magicoder-S-DS-6.7B, deepseek-coder-33b-instruct and GPT-4) on HPC_Fortran_CPP. And compared the CodeBlEU Score of the generated results.

The CodeBLEU Score Comparison is shown in the figure below:

![Example Image](Figures/CodeBLEU_Score.png)

### Reproduce Steps
1. Generate the results. Go the script `text_generation_pipline.py`. Add your own huggingface token to line 16. Modify the path where you want to store your results in line 55. Then select the model that you want to test between line 8 and line 13.

Run:
```
python text_generation_pipline.py
```

This will generate the results and compress each result to one line for the further CodeBLEU Score test.

2. Test CodeBLEU Score by using the following command

```
cd CodeBLEU
python calc_code_bleu.py --refs F2C-Translator/Groundtruth_C++.txt --hyp <path/to/your/results/txt/file> --lang cpp --params 0.25,0.25,0.25,0.25
```



## Inference and Demo



## Contact 

## Citation

## Acknowledgments
