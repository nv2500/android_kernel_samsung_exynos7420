# (0 = Disabled, 1 = Enabled)

#
# Disk optimizations
#
on late-fs
    # I/O sched settings
    write /sys/block/sda/queue/scheduler "cfq"
    #write /sys/block/sda/queue/scheduler cfq
    #write /sys/block/mmcblk0/queue/scheduler cfq
    write /sys/block/sda/queue/add_random 1
    write /sys/block/sda/queue/iostats 0
    #write /sys/block/mmcblk0/queue/iostats 0
    write /sys/block/sda/queue/nomerges 0
    write /sys/block/sda/queue/rotational 0
    write /sys/block/sda/queue/rq_affinity 1
    #write /sys/block/mmcblk0/queue/rq_affinity 1
    write /sys/block/sda/queue/read_ahead_kb 512
    #write /sys/block/mmcblk0/queue/read_ahead_kb 768    
    write /sys/block/sda/queue/nr_requests 256
    #write /sys/block/mmcblk0/queue/nr_requests 256

#
# init.power.rc
#
on init

# change own for camera preview lagging
    chown system system /sys/kernel/hmp/down_threshold

# set permission to 0660 for camera preview lagging
    chmod 0660 /sys/kernel/hmp/down_threshold

on boot

########## Set init values of the thunderstorm2 - Stock Kernel - START
   # CPU set at max/min freq
   # Little CPU
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
   write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor thunderstorm2
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
   write /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq 234000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
   write /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq 1586000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/go_hispeed_load
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/go_hispeed_load 95
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/above_hispeed_delay
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/above_hispeed_delay "30000 1066000:40000"
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/timer_rate
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/timer_rate 30000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/prev_timer_rate
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/prev_timer_rate 40000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/hispeed_freq
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/hispeed_freq 650000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/timer_slack
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/timer_slack 20000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/target_loads
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/target_loads "65 1066000:70"
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/min_sample_time
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/min_sample_time 40000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/mode
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/mode 0
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/boost
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/boost 0
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/io_is_busy
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/io_is_busy 0
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/param_index
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/param_index 0
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/boostpulse_duration
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/boostpulse_duration 30000
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/down_low_load_threshold 10
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/screen_off_max
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/screen_off_max 650000
   chmod 0644 /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/screen_off_timer_rate
   write /sys/devices/system/cpu/cpu0/cpufreq/thunderstorm2/screen_off_timer_rate 70000

   # Big CPU
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor
   write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor thunderstorm2
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/scaling_min_freq
   write /sys/devices/system/cpu/cpu4/cpufreq/scaling_min_freq 234000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq
   write /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq 1896000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/go_hispeed_load
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/go_hispeed_load 95
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/above_hispeed_delay
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/above_hispeed_delay "40000 1560000:49000 1664000:49000"
   # chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/timer_rate
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/timer_rate 30000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/prev_timer_rate
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/prev_timer_rate 40000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/hispeed_freq
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/hispeed_freq 1144000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/timer_slack
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/timer_slack 20000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/target_loads
   # write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/target_loads "70 1040000:75 1352000:78 1664000:80"
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/target_loads "80 343000:95 449000:90 546000:85 676000:85 757000:80 839000:80 902000:75 1014000:70 1144000:65 1248000:65 1352000:65 1482000:60 1586000:45 1690000:99 1794000:100"
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/min_sample_time
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/min_sample_time 40000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/mode
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/mode 0
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/boost
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/boost 0
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/io_is_busy
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/io_is_busy 0
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/param_index
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/param_index 0
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/boostpulse_duration
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/boostpulse_duration 30000
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/down_low_load_threshold 10
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/screen_off_max
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/screen_off_max 1040000
   chmod 0644 /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/screen_off_timer_rate
   write /sys/devices/system/cpu/cpu4/cpufreq/thunderstorm2/screen_off_timer_rate 70000
########## Set init values of the thunderstorm2 - Stock Kernel - END
# Kernel Panic off
   write /proc/sys/kernel/panic 0

# cpusets
    write /dev/cpuset/foreground/cpus 0-7
    write /dev/cpuset/foreground/boost/cpus 4-7
    write /dev/cpuset/background/cpus 0-4
    write /dev/cpuset/system-background/cpus 0-4
    write /dev/cpuset/top-app/cpus 4-7

# Change permission for dvfshelper
    chown radio system /sys/power/cpufreq_table
    chmod 0664 /sys/power/cpufreq_table
    chown radio system /sys/power/cpufreq_min_limit
    chmod 0664 /sys/power/cpufreq_min_limit
    chown radio system /sys/power/cpufreq_max_limit
    chmod 0664 /sys/power/cpufreq_max_limit

    chown radio system /sys/devices/system/cpu/kernel_max
    chmod 0664 /sys/devices/system/cpu/kernel_max

    # PMS DVFS
    chown radio system /sys/power/enable_dm_hotplug
    chmod 0664 /sys/power/enable_dm_hotplug
    chown bluetooth system /sys/power/cluster0_core_hotplug_in
    chmod 0664 /sys/power/cluster0_core_hotplug_in

    chown radio system /sys/power/ipa/control_temp
    chmod 0664 /sys/power/ipa/control_temp
    chown radio system /sys/power/ipa/hotplug_out_threshold
    chmod 0664 /sys/power/ipa/hotplug_out_threshold

    # Change permissions for the CPU governor settings
    chown system system /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
    chown system system /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
    chown system system /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
    chown system system /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
    chmod 0664 /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
    chmod 0664 /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
    chmod 0664 /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
    chmod 0664 /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
    chown system system /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq
    chown system system /sys/devices/system/cpu/cpu4/cpufreq/scaling_min_freq
    chown system system /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor
    chown system system /sys/devices/system/cpu/cpu4/cpufreq/scaling_cur_freq
    chmod 0664 /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq
    chmod 0664 /sys/devices/system/cpu/cpu4/cpufreq/scaling_min_freq
    chmod 0664 /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor
    chmod 0664 /sys/devices/system/cpu/cpu4/cpufreq/scaling_cur_freq

    # change permissions for all cpusets we touch at runtime
    chown system system /dev/cpuset/cpus
    chown system system /dev/cpuset/foreground/cpus
    chown system system /dev/cpuset/background/cpus
    chown system system /dev/cpuset/system-background/cpus
    chown system system /dev/cpuset/top-app/cpus
    chmod 0664 /dev/cpuset/cpus
    chmod 0664 /dev/cpuset/foreground/cpus
    chmod 0664 /dev/cpuset/background/cpus
    chmod 0664 /dev/cpuset/system-background/cpus
    chmod 0664 /dev/cpuset/top-app/cpus

    chown radio system /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/available_frequencies
    chmod 0664 /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/available_frequencies
    chown radio system /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/min_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/min_freq
    chown radio system /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/max_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-mif/devfreq/exynos7-devfreq-mif/max_freq
    chown radio system /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/available_frequencies
    chmod 0664 /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/available_frequencies
    chown radio system /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/min_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/min_freq
    chown radio system /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/max_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-int/devfreq/exynos7-devfreq-int/max_freq
    chown radio system /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/available_frequencies
    chmod 0664 /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/available_frequencies
    chown radio system /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/min_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/min_freq
    chown radio system /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/max_freq
    chmod 0664 /sys/devices/platform/exynos7-devfreq-isp/devfreq/exynos7-devfreq-isp/max_freq

    chown radio system /sys/devices/14ac0000.mali/dvfs
    chmod 0664 /sys/devices/14ac0000.mali/dvfs
    chown radio system /sys/devices/14ac0000.mali/dvfs_table
    chmod 0664 /sys/devices/14ac0000.mali/dvfs_table
    chown radio system /sys/devices/14ac0000.mali/dvfs_governor
    chmod 0664 /sys/devices/14ac0000.mali/dvfs_governor
    chown radio system /sys/devices/14ac0000.mali/dvfs_min_lock
    chmod 0664 /sys/devices/14ac0000.mali/dvfs_min_lock
    chown radio system /sys/devices/14ac0000.mali/dvfs_max_lock
    chmod 0664 /sys/devices/14ac0000.mali/dvfs_max_lock
    chown radio system /sys/devices/14ac0000.mali/highspeed_clock
    chmod 0664 /sys/devices/14ac0000.mali/highspeed_clock
    chown radio system /sys/devices/14ac0000.mali/highspeed_load
    chmod 0664 /sys/devices/14ac0000.mali/highspeed_load

    chown radio system /sys/devices/system/sec_os_ctrl/migrate_os
    chmod 0664 /sys/devices/system/sec_os_ctrl/migrate_os

    chown radio system /sys/module/cpuidle/parameters/off
    chmod 0664 /sys/module/cpuidle/parameters/off

    # HMP Status
    chown system system /sys/kernel/hmp/load_avg_period_ms
    chmod 0660 /sys/kernel/hmp/load_avg_period_ms
    chown system system /sys/kernel/hmp/up_threshold
    chmod 0660 /sys/kernel/hmp/up_threshold
    chown system system /sys/kernel/hmp/down_threshold
    chmod 0660 /sys/kernel/hmp/down_threshold

    # HMP Little Packing
    chown system system /sys/kernel/hmp/packing_enable
    chmod 0660 /sys/kernel/hmp/packing_enable
    chown system system /sys/kernel/hmp/packing_limit
    chmod 0660 /sys/kernel/hmp/packing_limit

    # Assume HMP uses shared cpufreq policy for all LITTLE CPUs
    chown system system /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
    chmod 0660 /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq

    chown system system sys/devices/system/cpu/cpufreq/mp-cpufreq/cluster0_max_freq
    chmod 0660 sys/devices/system/cpu/cpufreq/mp-cpufreq/cluster0_max_freq
    chown system system sys/devices/system/cpu/cpufreq/mp-cpufreq/boot_low_freq
    chmod 0660 sys/devices/system/cpu/cpufreq/mp-cpufreq/boot_low_freq

    # Assume HMP uses shared cpufreq policy for big CPUs
    chown system system /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq
    chmod 0660 /sys/devices/system/cpu/cpu4/cpufreq/scaling_max_freq

    # LITTLE cluster high load
    chown system system /sys/class/sec/sec_slow/timer_rate
    chmod 0660 /sys/class/sec/sec_slow/timer_rate
    chown system system /sys/class/sec/sec_slow/io_is_busy
    chmod 0660 /sys/class/sec/sec_slow/io_is_busy
    chown system system /sys/class/sec/sec_slow/slow_mode
    chmod 0660 /sys/class/sec/sec_slow/slow_mode
    chown system system /sys/class/sec/sec_slow/enforced_slow_mode
    chmod 0660 /sys/class/sec/sec_slow/enforced_slow_mode
    chown system system /sys/class/sec/sec_slow/full_enter_load
    chmod 0660 /sys/class/sec/sec_slow/full_enter_load
    chown system system /sys/class/sec/sec_slow/full_enter_load_fast
    chmod 0660 /sys/class/sec/sec_slow/full_enter_load_fast
    chown system system /sys/class/sec/sec_slow/full_exit_load
    chmod 0660 /sys/class/sec/sec_slow/full_exit_load
    chown system system /sys/class/sec/sec_slow/full_exit_load_fast
    chmod 0660 /sys/class/sec/sec_slow/full_exit_load_fast
    chown system system /sys/class/sec/sec_slow/full_enter_time
    chmod 0660 /sys/class/sec/sec_slow/full_enter_time
    chown system system /sys/class/sec/sec_slow/full_exit_time
    chmod 0660 /sys/class/sec/sec_slow/full_exit_time

# MSP Core Status
    chown system system /sys/devices/system/cpu/cpu0/online
    chmod 0664 /sys/devices/system/cpu/cpu0/online
    chown system system /sys/devices/system/cpu/cpu1/online
    chmod 0664 /sys/devices/system/cpu/cpu1/online
    chown system system /sys/devices/system/cpu/cpu2/online
    chmod 0664 /sys/devices/system/cpu/cpu2/online
    chown system system /sys/devices/system/cpu/cpu3/online
    chmod 0664 /sys/devices/system/cpu/cpu3/online
    chown system system /sys/devices/system/cpu/cpu4/online
    chmod 0664 /sys/devices/system/cpu/cpu4/online
    chown system system /sys/devices/system/cpu/cpu5/online
    chmod 0664 /sys/devices/system/cpu/cpu5/online
    chown system system /sys/devices/system/cpu/cpu6/online
    chmod 0664 /sys/devices/system/cpu/cpu6/online
    chown system system /sys/devices/system/cpu/cpu7/online
    chmod 0664 /sys/devices/system/cpu/cpu7/online

    # Make sure all cores are online on boot
	write /sys/devices/system/cpu/cpu0/online "1"
	write /sys/devices/system/cpu/cpu1/online "1"
	write /sys/devices/system/cpu/cpu2/online "1"
	write /sys/devices/system/cpu/cpu3/online "1"
	write /sys/devices/system/cpu/cpu4/online "1"
	write /sys/devices/system/cpu/cpu5/online "1"
	write /sys/devices/system/cpu/cpu6/online "1"
    write /sys/devices/system/cpu/cpu7/online "1"

# Setup cpusets with default values
    write /dev/cpuset/foreground/cpus          "0-7"
    write /dev/cpuset/background/cpus          "0-7"
    write /dev/cpuset/system-background/cpus   "0-7"
    write /dev/cpuset/top-app/cpus             "0-7"
    write /dev/cpuset/cpus                     "0-7"

    # Kernel Workqueue
	chown system system /sys/module/workqueue/parameters/power_efficient
    chmod 0644 /sys/module/workqueue/parameters/power_efficient

    # CPU Idle
    chown system system /sys/module/cpuidle_exynos64/parameters/enable_mask

    # DT2W Permissions
    chown system system /sys/class/dt2w/enabled
    chmod 0644 /sys/class/dt2w/enabled

    # Disable Adaptive Fast Charging
    write /sys/class/sec/switch/afc_disable 1
