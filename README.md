C++ CGI lib
=============

** [AUTHOR:] --	'Wn'
** [EMAIL:] --	'tharbad50@gmail.com'
** [DATE:] --	'2013-7-25'
** [DESCRIPTION:] --	 '一个简单的CGI库,练手项目'
           

@ 描述

	暂时考虑从http协议，cookie管理，html文档输出这三个方面来实现库。另会附着利用已完成类实现简单实用组件,作为Demo。


###最近的变动:

2013-7-25: 

- si_base类，基础类，cookie与httpHanlde 类将继承此类,此类作用是使得每个子类保有一个基础名称以识别和方便处理每个子类。

- 增加HtmlHelper.h.一个期望能简化输出html文档的类，类接口尚未设计
    
- 实现一个简单的uploadfile功能(仅仅能接受文本文件上传.图片等读取不全)


