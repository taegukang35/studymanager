from twilio.rest import Client
import serial
# 아두이노와 시리얼 통신 시작하는 부분
arduino = serial.Serial('COM9',9600)
# twilio API 이용

account_sid = 'AC53799d614439f810795a695bf5b980c9'
auth_token = '856449ef721d23737626dc30f15e45ce'
client = Client(account_sid, auth_token)

message1 = client.messages \
                .create(
                     body="강태구 학생 학습실로 복귀해주세요.",
                     from_='+12057404689',
                     to='+821093335418'
                 )
message2 = client.messages \
                .create(
                     body="허세환 학생 학습실로 복귀해주세요.",
                     from_='+12057404689',
                     to='+821021139648'
                 )
message3 = client.messages \
                .create(
                     body="김송희 학생 학습실로 복귀해주세요.",
                     from_='+12057404689',
                     to='+821037852146'
                 )

while True:
    # 시리얼 모니터에 출력한 값들을 가져옴.
    input = arduino.readline()
    # 아두이노에서 b'x x x\r\n' 형태로 시리얼 모니터로 넘겨오는데 이를 'x x x' 형태로 바꿔줌
    input = str(input).replace('b',"").replace('r',"").replace("n","").replace("\\","").replace("'","")
    # 'x x x' 형태를 공백을 기준으로 나눠 ['x','x','x'] 의 문자열로 바꿔줌
    Student = input.split(' ')
    # ['x','x','x'] 형태의 문자열을 [x,x,x]의 정수 list로 바꿔줌.
    Student = list(map(int,Student))
    print(Student)

    # 100cm보다 떨어져 있으면 학습실 밖에 위치해 있다고 가정후 메세지 보냄.
    if Student[0] > 100 : print(message1.sid)
    if Student[1] > 100: print(message2.sid)
    if Student[2] > 100: print(message3.sid)
