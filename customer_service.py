# -*- coding: utf-8 -*-
"""
customer_service.py —— 简易自动客服程序（本地关键词规则匹配）

零依赖、零 API key、可离线运行。
用法: python customer_service.py
"""

import sys

# ---------- 1. FAQ 知识库 ----------
# 每条包含 keywords（触发关键词）和 answer（回复内容）
FAQ = [
    {
        "keywords": ["退货", "退款", "退钱", "不满意"],
        "answer": "如需退货/退款：请在订单页点击\"申请售后\"，签收后 7 天内支持无理由退货，"
                  "审核通过后 1-3 个工作日原路退回款项。",
    },
    {
        "keywords": ["物流", "快递", "发货", "什么时候到", "到哪了", "配送", "运单"],
        "answer": "您的包裹发货后可在\"我的订单\"中查看物流轨迹。一般 1-3 天出库，"
                  "省内 1-2 天、跨省 3-5 天送达，偏远地区可能稍慢。",
    },
    {
        "keywords": ["改地址", "换地址", "修改地址", "地址填错"],
        "answer": "订单未发货前可在\"订单详情-修改地址\"自行更改；已发货则需联系配送员，"
                  "或致电客服 400-800-1234 协助拦截改派。",
    },
    {
        "keywords": ["优惠", "折扣", "打折", "优惠券", "满减", "活动"],
        "answer": "当前活动：全场满 199 减 30，新用户注册即送 15 元无门槛券。"
                  "优惠券可在结算页勾选使用，部分特价商品不参与满减。",
    },
    {
        "keywords": ["人工", "客服", "投诉", "电话", "联系"],
        "answer": "如需人工服务：请拨打 400-800-1234（9:00-21:00），"
                  "或发送\"转人工\"，我们会尽快为您接入专员。",
    },
    {
        "keywords": ["发票", "开票", "报销"],
        "answer": "发票可在\"订单详情-申请开票\"中填写抬头，电子发票开具后发送至您的邮箱，"
                  "纸质发票随订单或单独寄出。",
    },
    {
        "keywords": ["密码", "登录", "账号", "忘记", "找回"],
        "answer": "如忘记密码，请在登录页点击\"忘记密码\"，通过手机号/邮箱验证后即可重置；"
                  "账号异常可联系人工客服协助处理。",
    },
]

# 退出指令
EXIT_WORDS = ["退出", "再见", "拜拜", "exit", "quit", "bye"]

# 兜底回复
FALLBACK = "抱歉，我暂时没理解您的问题。您可以试试描述\"退货/物流/改地址/优惠\"等，或发送\"转人工\"。"


# ---------- 2. 匹配逻辑 ----------
def match(user_input):
    """遍历知识库，按命中关键词数量打分，返回得分最高的答案；无命中返回 None。"""
    best_answer = None
    best_score = 0
    for item in FAQ:
        score = sum(1 for k in item["keywords"] if k in user_input)
        if score > best_score:
            best_score = score
            best_answer = item["answer"]
    return best_answer if best_score > 0 else None


# ---------- 3. 主循环 ----------
def main():
    # Windows 终端中文输入输出编码适配（Python 3.7+）
    try:
        sys.stdin.reconfigure(encoding="utf-8")
        sys.stdout.reconfigure(encoding="utf-8")
    except AttributeError:
        pass  # 旧版 Python 或非文本流时忽略

    print("您好！我是智能客服小助手，很高兴为您服务。")
    print("您可以咨询：退货退款、物流发货、修改地址、优惠活动、开发票、账号问题等。")
    print("输入 \"退出\" 或 \"exit\" 结束对话。\n")

    while True:
        try:
            user_input = input("您: ").strip()
        except (EOFError, KeyboardInterrupt):
            print("\n对话已结束，感谢您的咨询，再见！")
            break

        if not user_input:
            continue

        if any(w in user_input.lower() for w in EXIT_WORDS):
            print("客服: 感谢您的咨询，祝您生活愉快，再见！")
            break

        answer = match(user_input)
        if answer:
            print("客服:", answer)
        else:
            print("客服:", FALLBACK)


if __name__ == "__main__":
    main()
