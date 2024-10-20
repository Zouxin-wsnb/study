from selenium import webdriver
from lxml import etree
import time
import os
import requests
import re

options = webdriver.ChromeOptions()
options.add_argument('--headless')  # 无头模式，不会显示浏览器界面
driver = webdriver.Chrome(options=options)

url = 'https://www.bilibili.com/anime/index/?from_spmid=666.4.index.0#st=1&order=4&season_version=-1&spoken_language_type=-1&area=-1&is_finish=-1&copyright=-1&season_status=-1&season_month=-1&year=-1&style_id=-1&sort=0&page=12'
driver.get(url)
time.sleep(5)  

html = driver.page_source
driver.quit()

html_object = etree.HTML(html) #解析
all_items = html_object.xpath('//li[@class="bangumi-item"]')

poster_dir_path = 'bilibili_poster'
os.makedirs(poster_dir_path, exist_ok=True)

for item in all_items:
    try:
        # 获取图片 URL
        poster_url_list = item.xpath('.//div[@class="common-lazy-img"]/img/@src')
        poster_url = poster_url_list[0]

        # 获取标题
        title_list = item.xpath('.//a[@class="bangumi-title"]/text()')
        title = title_list[0]
        if poster_url.startswith('//'):
            poster_url = 'https:' + poster_url

        print(title)
        print(poster_url)

        # 下载
        image_data = requests.get(url=poster_url).content

        # 保存
        image_path = f'{poster_dir_path}/{title}.jpg'
        with open(image_path, 'wb') as f:
            f.write(image_data)
        print(f'Downloaded {image_path}')
        time.sleep(1)  
    
    except:continue
