import threading
import requests
class Download():
    def download(self,url,callback_world_count):
        print(f'线程{threading.get_ident()},正在下载{url}...')
        response = requests.get(url)
        response.encoding = 'utf-8'
        callback_world_count(url,response.text)
    def start_download(self,url,callback_world_count):
        # self.download(url,callback_world_count)
        thread = threading.Thread(target=self.download,args=(url,callback_world_count)) #创建线程对象
        thread.start() #启动线程
def world_count(url,result):
    '''
    回调函数，统计单词数量
    '''
    print(f'{url}:{len(result)}--{result[0:5]}')
def main():
    download = Download()
    download.start_download('http://0.0.0.0:8000/novel1.txt',world_count)
    download.start_download('http://0.0.0.0:8000/novel2.txt',world_count)
    download.start_download('http://0.0.0.0:8000/novel3.txt',world_count)
