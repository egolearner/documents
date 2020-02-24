* set dns
```bash
# 得到网络名称，如Wi-Fi
networksetup -listallnetworkservices
# 得到已有dns
networksetup -getdnsservers Wi-fi
# 设置dns
sudo networksetup -setdnsservers Wi-fi server1 server2
# 在已有dns基础上插入
sudo networksetup -setdnsservers Wi-fi 8.8.8.8 `networksetup -getdnsservers Wi-fi`
```

* 系统自带的可视化截图
快捷键`Cmd+Shift+5`，可以设置保存的目录，截图后可以调用Preview编辑。点`Capture`的时候按住`control`键可以复制到剪贴板。然而没找到Preview编辑后再复制到粘贴板的操作。相比其他的截图软件还是不好用，好在可以救急。

* Rime配置
```bash
# 备份配置然后重装
mv ~Library/Rime{,.bak}
# 安装超强音形
'/Library/Input Methods/Squirrel.app/Contents/MacOS/rime-install' pinyin-simp whjiang/cqeb
# 创建配置
cat > defaut.custom.yaml <<EOF
patch:
  schema_list:
    - {schema: cqkm} #超强快码
    - {schema: cqyx} #超强音形
    - {schema: luna_pinyin_simp} #pinyin
EOF
# 配置部分标点cqyx.schema.yaml
punctuator:
  import_preset: default
  full_shape:
    "/" : "、"
  half_shape:
    "/" : "、"
    '%' : '%'
    '*' : '*'
```