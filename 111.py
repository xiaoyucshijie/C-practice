from openai import OpenAI

client = OpenAI(
    api_key = "sk-your_api_key",
    base_url = "https://token.nuaa.edu.cn/v1",
)

response = client.chat.completions.create(
    model = "your_model_id",
    messages = [
      {"role": "system", "content": "You are a helpful assistant."},
      {"role": "user", "content": "你好，请介绍一下你自己"},
    ],
)
print(response.choices[0].message.content)