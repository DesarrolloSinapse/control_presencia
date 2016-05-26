import smtplib
subjecttxt = "My subject!"
content = "Some text."
message = 'Subject: %s\n\n%s' % (subjecttxt, content)
mail = smtplib.SMTP("smtp.gmail.com",587)
#mail = smtplib.SMTP("smtp.gmail.com",465)
mail.ehlo()
mail.starttls()
mail.login("lacelia@gmail.com","yo.3misma")
mail.sendmail("Cancelor","lacelia@gmail.com",message)
mail.close()
