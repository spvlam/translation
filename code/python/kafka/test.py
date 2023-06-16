from kafka import KafkaProducer, KafkaConsumer
from json import dumps, loads

producer = KafkaProducer(
    bootstrap_servers=['localhost:9092'],
    value_serializer = lambda x: dumps(x).encode('utf-8')
)

consumer = KafkaConsumer(
    'test-topic',
     bootstrap_servers=['localhost:9092'],
     auto_offset_reset='earliest',
    enable_auto_commit=True,
    group_id='my-group-id',
    value_deserializer=lambda x: loads(x.decode('utf-8'))
)
message = {'key': 'value'}
message2= {'test' : "abc"}
producer.send('test-topic', value=message)
producer.send('test-topic',value = message2)
for msg in consumer:
    print(msg.value)

