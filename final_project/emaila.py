def emailservice(email,content):
    import smtplib
    from email.mime.text import MIMEText
    html1 = '''
    <h1>MOD CHANGE</h1>
    <h2>MOD is changed to Detect</h2>
    '''
    html0 = '''
    <h1>MOD CHANGE</h1>
    <h2>MOD is changed to No Detect</h2>
    '''
    html2 = '''
    <h1>MOD CHANGE WARING</h1>
    <h1>Because time too long run No Detect mod,system is changed to Detect </h1>
    <div>MOD is changed to Detect</div>
    '''
    if(content == 'detect'): html = html0
    elif(content == 'no_dect'): html = html1
    elif(content == '2'): html = html2
    mail = MIMEText(html, 'html', 'utf-8')   # plain 換成 html，就能寄送 HTML 格式的信件
    mail['Subject']='微算機實習＿期末專題—模式切換'
    mail['From']='t109590010@ntut.edu.tw'
    mail['To']=email


    with smtplib.SMTP(host="smtp.ntut.edu.tw", port="587") as smtp:  # 設定SMTP伺服器
        try:
            smtp.ehlo()  # 驗證SMTP伺服器
            smtp.starttls()  # 建立加密傳輸
            smtp.login("t109590010@ntut.edu.tw", "*Ss34218272")  # 登入寄件者gmails
            smtp.send_message(mail)  # 寄送郵件
            print("Complete!")
        except Exception as e:
            print("Error message: ", e)



import sys


emailservice("jjkk900925@gmail.com",sys.argv[1])
