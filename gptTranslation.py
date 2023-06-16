import requests
import json
import threading
import traceback
import time
from pymongo import MongoClient

class requestToGPT:
    def __init__(self,url,header):
        self.url = url
        self.header = header
    def payLoadInitilize(self,text):
        payload = {
                "model": "gpt-3.5-turbo",
                "messages": [{"role": "user", "content": f"translate \"{text}\" to vi"}],
                "temperature": 0.7
                }
        # the better command for payload
        """
          "content": "Translate from " + sourceLanguage + " to " + targetLanguage + ": " + text
        """
        return payload
    def requestOneTime(self,text):
        payload=self.payLoadInitilize(text)
        response= requests.post(url=self.url,headers=self.header,data=json.dumps(payload))
        responseJson = response.json()
        # remove the quotation in string
        StringFinal = responseJson['choices'][0]['message']['content']
        StringFinal = StringFinal[:-1]
        StringFinal = StringFinal[1:]
        # return responseJson['choices'][0]['message']['content']
        return StringFinal
    def request_Array_object(self,array_Object):
        """
        one thread running 
        """
        # stop_flag = threading.Event()
        # even for control all thread 
        for num,obj in enumerate(array_Object):
            text = obj['doc']['m']['en']
            id_detail=obj['id']
            try:
                text_translated = self.requestOneTime(text)
                filter = {"id":id_detail}   
                update_item = {"$set":{
                    "doc.m.vi":text_translated,
                    "translated":"true",
                    "language":["en","vi"]
                    }
                }
                self.col.update_one(filter,update_item)
                print(num)
            except:
                # stop_flag.set()
                time.sleep(15)
                traceback_str = traceback.format_exc()
                print(traceback_str)
                continue           
    def requestByThread(self,array_Object,numberOfThread):
        """
        input : ["array of sentences have been translated "]
        output : ["array of translated sentences"]
        method: run by thread
        """
        chuckSize=len(array_Object)//numberOfThread
        chuckS = [array_Object[i:i+chuckSize] for i in range(0,len(array_Object),chuckSize)]
        # translate_text_result = [None]*(len(chuckS)-1)

        # start thread
        threads = []
        for i in range(numberOfThread):
            # it is not necessary to build a threading in below
            # thread = threading.Thread(target=lambda i , chuck : translate_text_result.__setitem__(i,self.request_Array_object(chuck)), args=(i,chuckS[i]))
            thread = threading.Thread(target=self.request_Array_object,args=(chuckS[i],))
            # note that must have " , " at the end of args
            thread.start()
            threads.append(thread)
        # wait for all threading complete
        for thread in threads:
            thread.join()
    # mongose action
    def connect_mongose(self,url,database,col):
        self.client = MongoClient(url)
        self.db = self.client[database]
        self.col= self.db[col]
    def get_arr_obj(self,filter,size):
        """
        filter={"translated":"false"}
        """
        self.arrayData =  list(self.col.find(filter).limit(size))
        
if __name__ =='__main__':
    url = "https://api.openai.com/v1/chat/completions"
    headers = {
        "Content-Type": "application/json",
        "Authorization": "Bearer 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"
    }
    # create object
    translationGPT = requestToGPT(url,headers)
    # connect and get array of data
    mongose_url = "mongodb+srv://lamnv2:lamnv123@cluster0.zzvcddy.mongodb.net/?retryWrites=true&w=majority"
    translationGPT.connect_mongose(mongose_url,"faztaa","faztaa")
    for i in range(5):
        translationGPT.get_arr_obj({"translated":"false"},10000)
        if(len(translationGPT.arrayData)==0):
            break
        else:
            translationGPT.requestByThread(translationGPT.arrayData,1)
            time.sleep(120)
    
  
