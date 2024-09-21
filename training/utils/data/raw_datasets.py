# Copyright (c) Microsoft Corporation.
# SPDX-License-Identifier: Apache-2.0

# DeepSpeed Team
from datasets import load_dataset
from torch.utils.data import Subset
import re


# The template prompt dataset class that all new dataset porting needs to
# follow in order to have a unified API and unified data format.
class PromptRawDataset(object):

    def __init__(self, output_path, seed, local_rank):
        self.output_path = output_path
        self.seed = seed
        self.local_rank = local_rank

    def get_train_data(self):
        return

    def get_eval_data(self):
        return

    # The prompt should be in the format of: " Human: " + actual_prompt_sentence + " Assistant:"
    def get_prompt(self, sample):
        return

    # The chosen response should be in the format of: " " + actual_response_sentence
    def get_chosen(self, sample):
        return

    # The rejected response should be in the format of: " " + actual_response_sentence
    # If the dataset does not have rejected response, return None
    def get_rejected(self, sample):
        return

    def get_prompt_and_chosen(self, sample):
        return

    def get_prompt_and_rejected(self, sample):
        return


# English dataset
class DahoasRmstaticDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Dahoas/rm-static"
        self.dataset_name_clean = "Dahoas_rm_static"
        self.raw_datasets = load_dataset("Dahoas/rm-static")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["test"]

    def get_prompt(self, sample):
        return sample['prompt']

    def get_chosen(self, sample):
        return sample['chosen']

    def get_rejected(self, sample):
        return sample['rejected']

    def get_prompt_and_chosen(self, sample):
        return sample['prompt'] + sample['chosen']

    def get_prompt_and_rejected(self, sample):
        return sample['prompt'] + sample['rejected']


# English dataset
class DahoasFullhhrlhfDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Dahoas/full-hh-rlhf"
        self.dataset_name_clean = "Dahoas_full_hh_rlhf"
        self.raw_datasets = load_dataset("Dahoas/full-hh-rlhf")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["test"]

    def get_prompt(self, sample):
        return sample['prompt']

    def get_chosen(self, sample):
        return sample['chosen']

    def get_rejected(self, sample):
        return sample['rejected']

    def get_prompt_and_chosen(self, sample):
        return sample['prompt'] + sample['chosen']

    def get_prompt_and_rejected(self, sample):
        return sample['prompt'] + sample['rejected']


# English dataset
class DahoasSyntheticinstructgptjpairwiseDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Dahoas/synthetic-instruct-gptj-pairwise"
        self.dataset_name_clean = "Dahoas_synthetic_instruct_gptj_pairwise"
        self.raw_datasets = load_dataset(
            "Dahoas/synthetic-instruct-gptj-pairwise")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        return " Human: " + sample['prompt'] + " Assistant:"

    def get_chosen(self, sample):
        return " " + sample['chosen']

    def get_rejected(self, sample):
        return " " + sample['rejected']

    def get_prompt_and_chosen(self, sample):
        return " Human: " + sample['prompt'] + " Assistant: " + sample['chosen']

    def get_prompt_and_rejected(self, sample):
        return " Human: " + sample['prompt'] + " Assistant: " + sample[
            'rejected']


# English dataset
class YitingxieRlhfrewarddatasetsDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "yitingxie/rlhf-reward-datasets"
        self.dataset_name_clean = "yitingxie_rlhf_reward_datasets"
        self.raw_datasets = load_dataset("yitingxie/rlhf-reward-datasets")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["test"]

    def get_prompt(self, sample):
        return sample['prompt'] + "Assistant:"

    def get_chosen(self, sample):
        return sample['chosen'].split("Assistant:")[-1]

    def get_rejected(self, sample):
        return sample['rejected'].split("Assistant:")[-1]

    def get_prompt_and_chosen(self, sample):
        return sample['prompt'] + sample['chosen']

    def get_prompt_and_rejected(self, sample):
        return sample['prompt'] + sample['rejected']


# English dataset
class OpenaiWebgptcomparisonsDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "openai/webgpt_comparisons"
        self.dataset_name_clean = "openai_webgpt_comparisons"
        self.raw_datasets = load_dataset("openai/webgpt_comparisons")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        return " Human: " + sample['question']['full_text'] + " Assistant:"

    def get_chosen(self, sample):
        if float(sample['score_0']) >= float(sample['score_1']):
            response = sample['answer_0']
        else:
            response = sample['answer_1']
        # This data has citation square brackets and numbers (e.g., "[1]").
        # Right now we are not doing browser-assisted finetuning, thus we
        # remove these citations to avoid confusing the model.
        response = re.sub(r" [\(\[].*?[\)\]]", "", response)
        response = re.sub(r"[\(\[].*?[\)\]]", "", response)
        return " " + response

    def get_rejected(self, sample):
        if float(sample['score_0']) < float(sample['score_1']):
            response = sample['answer_0']
        else:
            response = sample['answer_1']
        response = re.sub(r" [\(\[].*?[\)\]]", "", response)
        response = re.sub(r"[\(\[].*?[\)\]]", "", response)
        return " " + response

    def get_prompt_and_chosen(self, sample):
        if float(sample['score_0']) >= float(sample['score_1']):
            response = sample['answer_0']
        else:
            response = sample['answer_1']
        response = re.sub(r" [\(\[].*?[\)\]]", "", response)
        response = re.sub(r"[\(\[].*?[\)\]]", "", response)
        return " Human: " + sample['question'][
            'full_text'] + " Assistant: " + response

    def get_prompt_and_rejected(self, sample):
        if float(sample['score_0']) < float(sample['score_1']):
            response = sample['answer_0']
        else:
            response = sample['answer_1']
        response = re.sub(r" [\(\[].*?[\)\]]", "", response)
        response = re.sub(r"[\(\[].*?[\)\]]", "", response)
        return " Human: " + sample['question'][
            'full_text'] + " Assistant: " + response


# English dataset
class StanfordnlpSHPDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "stanfordnlp/SHP"
        self.dataset_name_clean = "stanfordnlp_SHP"
        self.raw_datasets = load_dataset("stanfordnlp/SHP")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["validation"]

    def get_prompt(self, sample):
        return " Human: " + sample['history'] + " Assistant:"

    def get_chosen(self, sample):
        if int(sample["labels"]) == 1:
            response = sample["human_ref_A"]
        else:
            response = sample["human_ref_B"]
        return " " + response

    def get_rejected(self, sample):
        if int(sample["labels"]) == 1:
            response = sample["human_ref_B"]
        else:
            response = sample["human_ref_A"]
        return " " + response

    def get_prompt_and_chosen(self, sample):
        if int(sample["labels"]) == 1:
            response = sample["human_ref_A"]
        else:
            response = sample["human_ref_B"]
        return " Human: " + sample['history'] + " Assistant: " + response

    def get_prompt_and_rejected(self, sample):
        if int(sample["labels"]) == 1:
            response = sample["human_ref_B"]
        else:
            response = sample["human_ref_A"]
        return " Human: " + sample['history'] + " Assistant: " + response


# Chinese dataset
class Wangrui6ZhihuKOLDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "wangrui6/Zhihu-KOL"
        self.dataset_name_clean = "wangrui6_Zhihu_KOL"
        self.raw_datasets = load_dataset("wangrui6/Zhihu-KOL")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        if sample['INSTRUCTION'] is not None:
            return " Human: " + sample['INSTRUCTION'] + " Assistant:"
        return None

    def get_chosen(self, sample):
        if sample['RESPONSE'] is not None:
            return " " + sample['RESPONSE']
        return None

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        if sample['INSTRUCTION'] is not None and sample['RESPONSE'] is not None:
            return " Human: " + sample[
                'INSTRUCTION'] + " Assistant: " + sample['RESPONSE']
        return None

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# Chinese dataset
class CohereMiraclzhqueries2212Dataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Cohere/miracl-zh-queries-22-12"
        self.dataset_name_clean = "Cohere_miracl_zh_queries_22_12"
        self.raw_datasets = load_dataset("Cohere/miracl-zh-queries-22-12")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["dev"]

    def get_prompt(self, sample):
        return " Human: " + sample['query'] + " Assistant:"

    def get_chosen(self, sample):
        return " " + sample['positive_passages'][0]['text']

    def get_rejected(self, sample):
        return " " + sample['negative_passages'][0]['text']

    def get_prompt_and_chosen(self, sample):
        return " Human: " + sample['query'] + " Assistant: " + sample[
            'positive_passages'][0]['text']

    def get_prompt_and_rejected(self, sample):
        return " Human: " + sample['query'] + " Assistant: " + sample[
            'negative_passages'][0]['text']


# Chinese dataset
class HelloSimpleAIHC3ChineseDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Hello-SimpleAI/HC3-Chinese"
        self.dataset_name_clean = "Hello_SimpleAI_HC3_Chinese"
        self.raw_datasets = load_dataset("Hello-SimpleAI/HC3-Chinese", "all")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        if sample['question'] is not None:
            return " Human: " + sample['question'] + " Assistant:"
        return None

    def get_chosen(self, sample):
        if sample['human_answers'][0] is not None:
            return " " + sample['human_answers'][0]
        return None

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        if sample['question'] is not None and sample['human_answers'][
                0] is not None:
            return " Human: " + sample['question'] + " Assistant: " + sample[
                'human_answers'][0]
        return None

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# Chinese dataset
class MkqaChineseDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "mkqa-Chinese"
        self.dataset_name_clean = "mkqa"
        self.raw_datasets = load_dataset("mkqa")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        if sample['queries']['zh_cn'] is not None:
            return " Human: " + sample['queries']['zh_cn'] + " Assistant:"
        return None

    def get_chosen(self, sample):
        if sample['answers']['zh_cn'][0]['text'] is not None:
            return " " + sample['answers']['zh_cn'][0]['text']
        return None

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        if sample['queries']['zh_cn'] is not None and sample['answers'][
                'zh_cn'][0]['text'] is not None:
            return " Human: " + sample['queries'][
                'zh_cn'] + " Assistant: " + sample['answers']['zh_cn'][0][
                    'text']
        return None

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# Japanese dataset
class MkqaJapaneseDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "mkqa-Japanese"
        self.dataset_name_clean = "mkqa"
        self.raw_datasets = load_dataset("mkqa")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        if sample['queries']['ja'] is not None:
            return " Human: " + sample['queries']['ja'] + " Assistant:"
        return None

    def get_chosen(self, sample):
        if sample['answers']['ja'][0]['text'] is not None:
            return " " + sample['answers']['ja'][0]['text']
        return None

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        if sample['queries']['ja'] is not None and sample['answers']['ja'][0][
                'text'] is not None:
            return " Human: " + sample['queries'][
                'ja'] + " Assistant: " + sample['answers']['ja'][0]['text']
        return None

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# Japanese dataset
class CohereMiracljaqueries2212Dataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Cohere/miracl-ja-queries-22-12"
        self.dataset_name_clean = "Cohere_miracl_ja_queries_22_12"
        self.raw_datasets = load_dataset("Cohere/miracl-ja-queries-22-12")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["dev"]

    def get_prompt(self, sample):
        return " Human: " + sample['query'] + " Assistant:"

    def get_chosen(self, sample):
        return " " + sample['positive_passages'][0]['text']

    def get_rejected(self, sample):
        return " " + sample['negative_passages'][0]['text']

    def get_prompt_and_chosen(self, sample):
        return " Human: " + sample['query'] + " Assistant: " + sample[
            'positive_passages'][0]['text']

    def get_prompt_and_rejected(self, sample):
        return " Human: " + sample['query'] + " Assistant: " + sample[
            'negative_passages'][0]['text']


# Japanese dataset
class LmqgQgjaquadDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "lmqg/qg_jaquad"
        self.dataset_name_clean = "lmqg_qg_jaquad"
        self.raw_datasets = load_dataset("lmqg/qg_jaquad")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["validation"]

    def get_prompt(self, sample):
        return " Human: " + sample['question'] + " Assistant:"

    def get_chosen(self, sample):
        return " " + sample['sentence']

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        return " Human: " + sample['question'] + " Assistant: " + sample[
            'sentence']

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# Japanese dataset
class LmqgQagjaquadDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "lmqg/qag_jaquad"
        self.dataset_name_clean = "lmqg_qag_jaquad"
        self.raw_datasets = load_dataset("lmqg/qag_jaquad")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["validation"]

    def get_prompt(self, sample):
        return " Human: " + sample['questions'][0] + " Assistant:"

    def get_chosen(self, sample):
        return " " + sample['paragraph']

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        return " Human: " + sample['questions'][0] + " Assistant: " + sample[
            'paragraph']

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# code contest dataset
class CodecontestDataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "deepmind/code_contests"
        self.dataset_name_clean = "deepmind_code_contests"
        self.raw_datasets = load_dataset("deepmind/code_contests")

    def get_train_data(self):
        return self.raw_datasets["train"]

    def get_eval_data(self):
        return self.raw_datasets["valid"]

    def get_prompt(self, sample):
        return sample['description']

    def get_chosen(self, sample):
        input_text = next(iter(sample['public_tests']["input"]), "")
        output_text = next(iter(sample['public_tests']["output"]), "")
        return input_text + output_text

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    # def get_prompt_and_chosen(self, sample):
    #     return sample['description'] + sample['public_tests']["input"][0] + sample['public_tests']["output"][0]
    def get_prompt_and_chosen(self, sample):
        input_text = next(iter(sample['public_tests']["input"]), "")
        output_text = next(iter(sample['public_tests']["output"]), "")
        return sample['description'] + input_text + output_text

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


# code contest dataset
class Fortran_Python_Dataset(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Bin12345/fortran-python"
        self.dataset_name_clean = "Bin12345_fortran-python"
        self.raw_datasets = load_dataset("Bin12345/fortran-python")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        return "Translate the following Python code to Fortran"+sample['Python']

    def get_chosen(self, sample):
        return sample['Fortran']

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    # def get_prompt_and_chosen(self, sample):
    #     return sample['description'] + sample['public_tests']["input"][0] + sample['public_tests']["output"][0]
    def get_prompt_and_chosen(self, sample):
        return "Translate the following Python code to Fortran"+sample['Python']+sample['Fortran']

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None
    
    
# code contest dataset
class HPC_Fortran_CPP(PromptRawDataset):

    def __init__(self, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = "Bin12345/HPC_Fortran_CPP"
        self.dataset_name_clean = "Bin12345_HPC_Fortran_CPP"
        self.raw_datasets = load_dataset("Bin12345/HPC_Fortran_CPP")

    def get_train_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 0,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_eval_data(self):
        from .data_utils import get_raw_dataset_split_index
        dataset = self.raw_datasets["train"]
        index = get_raw_dataset_split_index(self.local_rank, self.output_path,
                                            self.dataset_name_clean,
                                            self.seed, "train_eval", "9,1", 1,
                                            len(dataset))
        dataset = Subset(dataset, index)
        return dataset

    def get_prompt(self, sample):
        return "Translate the following fortran code to cpp"+sample['fortran']

    def get_chosen(self, sample):
        return sample['cpp']

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    # def get_prompt_and_chosen(self, sample):
    #     return sample['description'] + sample['public_tests']["input"][0] + sample['public_tests']["output"][0]
    def get_prompt_and_chosen(self, sample):
        return "Translate the following fortran code to cpp"+sample['fortran']+sample['cpp']

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


class Local_Dataset(PromptRawDataset):
    def __init__(self, dataset_name, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = dataset_name
        self.dataset_name_clean = dataset_name.replace("/", "_")
        self.raw_datasets = load_dataset(dataset_name)

    def get_train_data(self):
        dataset = self.raw_datasets["train"]
        return dataset

    def get_eval_data(self):
        dataset = self.raw_datasets["validation"]
        return dataset

    # def get_prompt(self, sample):
    #     return "<s>Translate the following fortran code to cpp"+sample['fortran'] # Needs to be changed to be more universal

    def get_prompt(self, sample):
        return "Translate the following fortran code to cpp:\n"+sample['fortran'] # Needs to be changed to be more universal

    # def get_chosen(self, sample):
    #     return sample['cpp'] + "</s>"

    def get_chosen(self, sample):
        return sample['cpp']

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    # def get_prompt_and_chosen(self, sample):
    #     # print("sample['fortran']",sample['fortran'])
    #     # print("sample['cpp']",sample['cpp'])
    #     return "<s>Translate the following fortran code to cpp"+ sample['fortran']+sample['cpp'] + "</s>"
    
    def get_prompt_and_chosen(self, sample):
        # print("sample['fortran']",sample['fortran'])
        # print("sample['cpp']",sample['cpp'])
        return "Translate the following fortran code to cpp:\n"+ sample['fortran']+sample['cpp']

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None


class Local_Dataset_reward(PromptRawDataset):
    def __init__(self, dataset_name, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = dataset_name
        self.dataset_name_clean = dataset_name.replace("/", "_")
        self.raw_datasets = load_dataset(dataset_name)

    def get_train_data(self):
        dataset = self.raw_datasets["train"]
        return dataset

    def get_eval_data(self):
        dataset = self.raw_datasets["validation"]
        return dataset

    def get_prompt(self, sample):
        return '''<s>Help me to assess if the translated C++ is correct.''' + "\nSource fortran code: " + sample['fortran'] + "\nTranslated C++ Code: " + sample['cpp']
                  

    def get_chosen(self, sample):
        if sample['result'] == True:
            return "\nAnswer:\n"+ "Yes" + "</s>"
        elif sample['result'] == False:
            if sample['reason'] != None:
                return "\nAnswer:\n" + "\nNo\n" + "\nReason:\n" + sample['reason'] + "</s>"
            else:
                return "\nAnswer:\n" + "\nNo\n" + "\nReason:\n" + "Too many errors" + "</s>"
        

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        # print("sample['fortran']",sample['fortran'])
        # print("sample['cpp']",sample['cpp'])
        if sample['result'] == True:
            return '''<s>Help me to assess if the translated C++ is correct.''' + "\nSource fortran code: " + sample['fortran'] + "\nTranslated C++ Code: " + sample['cpp'] + "\nAnswer:\n"+ "Yes" + "</s>"
        elif sample['result'] == False:
            if sample['reason'] != None:
                return '''<s>Help me to assess if the translated C++ is correct.''' + "\nSource fortran code: " + sample['fortran'] + "\nTranslated C++ Code: " + sample['cpp'] + "\nAnswer:\n" + "\nNo\n" + "\nReason:\n" + sample['reason'] + "</s>"
            else:
                return '''<s>Help me to assess if the translated C++ is correct.''' + "\nSource fortran code: " + sample['fortran'] + "\nTranslated C++ Code: " + sample['cpp'] + "\nAnswer:\n" + "\nNo\n" + "\nReason:\n" + "Too many errors" + "</s>"                

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None
    
class Local_Multi_Dialogue(PromptRawDataset):
    def __init__(self, dataset_name, output_path, seed, local_rank):
        super().__init__(output_path, seed, local_rank)
        self.dataset_name = dataset_name
        self.dataset_name_clean = dataset_name.replace("/", "_")
        # print("self.dataset_name_clean",dataset_name)
        self.raw_datasets = load_dataset(dataset_name) 
        # self.raw_datasets = load_dataset(dataset_name,
        #                                  download_mode="force_redownload")

    def get_train_data(self):
        dataset = self.raw_datasets["train"]
        return dataset

    def get_eval_data(self):
        dataset = self.raw_datasets["validation"]
        return dataset

    def get_prompt(self, sample):
        return sample['prompt']
                  
    def get_chosen(self, sample):
        return sample['response']
        

    def get_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None

    def get_prompt_and_chosen(self, sample):
        # print("sample['fortran']",sample['fortran'])
        # print("sample['cpp']",sample['cpp'])
        return sample['prompt'] + sample['response']            

    def get_prompt_and_rejected(self, sample):
        print(
            f"Warning: dataset {self.dataset_name} does not include rejected response."
        )
        return None