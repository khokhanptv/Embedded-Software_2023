#!/bin/bash

# Đường dẫn đến thư mục nguồn và thư mục sao lưu
SOURCE_DIR="/d/Embeded_T10/ADVANCED CC++ ALGORITHM T122023_BT"
BACKUP_DIR="/d/backup"
LOG_FILE="/d/backup/backup.log"
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")

# Tạo thư mục sao lưu nếu chưa tồn tại
mkdir -p "$BACKUP_DIR"

# Sao lưu thư mục và tạo tệp nén
tar -czf "$BACKUP_DIR/backup_$TIMESTAMP.tar.gz" -C "$SOURCE_DIR" . 2>>"$LOG_FILE"

if [ $? -eq 0 ]; then
    echo "[$TIMESTAMP] Backup completed successfully" >> "$LOG_FILE"
else
    echo "[$TIMESTAMP] Backup failed" >> "$LOG_FILE"
fi
