#!/bin/bash
# kernel build script by Tkkg1994 v0.6 (optimized from apq8084 kernel source)

export MODEL=noblelte
export ARCH=arm64

# Kernel Variables
CR_VERSION=Q.2.1
CR_NAME=khoailang2500
CR_JOBS=5
CR_ANDROID=q
CR_PLATFORM=10.0.0
CR_ARCH=arm64
CR_DATE=$(date +%Y%m%d)
# Init build
export CROSS_COMPILE=$CR_TC
export ANDROID_MAJOR_VERSION=$CR_ANDROID
export PLATFORM_VERSION=$CR_PLATFORM
export $CR_ARCH

# GG Cloud setup
export BUILD_CROSS_COMPILE=../tools/aarch64-linux-android-4.9/bin/aarch64-linux-android-
# export BUILD_CROSS_COMPILE=../tools/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-

export BUILD_JOB_NUMBER=5

export LOCALVERSION=-$CR_NAME-$CR_VERSION

RDIR=$(pwd)
OUTDIR=$RDIR/arch/$ARCH/boot
DTSDIR=$RDIR/arch/$ARCH/boot/dts
DTBDIR=$OUTDIR/dtb
DTCTOOL=$RDIR/scripts/dtc/dtc
INCDIR=$RDIR/include

PAGE_SIZE=2048
DTB_PADDING=0

KERNEL_DEFCONFIG=lineageos_noblelte_defconfig

FUNC_CLEAN_DTB()
{
	# remove/reset build version
	rm $RDIR/.version

	if ! [ -d $RDIR/arch/$ARCH/boot/dts ] ; then
		echo "no directory : "$RDIR/arch/$ARCH/boot/dts""
	else
		echo "rm files in : "$RDIR/arch/$ARCH/boot/dts/*.dtb""
		rm $RDIR/arch/$ARCH/boot/dts/*.dtb
		rm $RDIR/arch/$ARCH/boot/dtb/*.dtb
		rm $RDIR/arch/$ARCH/boot/boot.img-dtb
		rm $RDIR/arch/$ARCH/boot/boot.img-zImage
	fi
}

FUNC_BUILD_DTIMAGE_TARGET()
{
	[ -f "$DTCTOOL" ] || {
		echo "You need to run ./build.sh first!"
		exit 1
	}

	# DTSFILES="exynos7420-noblelte_usa_09"
	# DTSFILES="exynos7420-noblelte_eur_open_09"
	DTSFILES="exynos7420-noblelte_eur_open_00 exynos7420-noblelte_eur_open_01 exynos7420-noblelte_eur_open_02 exynos7420-noblelte_eur_open_03 exynos7420-noblelte_eur_open_04 exynos7420-noblelte_eur_open_05 exynos7420-noblelte_eur_open_06 exynos7420-noblelte_eur_open_08 exynos7420-noblelte_eur_open_09"

	mkdir -p $OUTDIR $DTBDIR

	cd $DTBDIR || {
		echo "Unable to cd to $DTBDIR!"
		exit 1
	}

	rm -f ./*

	echo "Processing dts files..."

	for dts in $DTSFILES; do
		echo "=> Processing: ${dts}.dts"
		${CROSS_COMPILE}cpp -nostdinc -undef -x assembler-with-cpp -I "$INCDIR" "$DTSDIR/${dts}.dts" > "${dts}.dts"
		#${BUILD_CROSS_COMPILE}cpp -nostdinc -undef -x assembler-with-cpp -I "$INCDIR" "$DTSDIR/${dts}.dts" > "${dts}.dts"
		echo "=> Generating: ${dts}.dtb"
		$DTCTOOL -p $DTB_PADDING -i "$DTSDIR" -O dtb -o "${dts}.dtb" "${dts}.dts"
	done

	echo "Generating dtb.img..."
	$RDIR/scripts/dtbTool/dtbTool -o "$OUTDIR/dtb.img" -d "$DTBDIR/" -s $PAGE_SIZE

	echo "Done."
}

FUNC_BUILD_KERNEL()
{
	echo ""
    echo "=============================================="
    echo "START : FUNC_BUILD_KERNEL"
    echo "=============================================="
    echo ""
    echo "build common config="$KERNEL_DEFCONFIG ""
    echo "build variant config="$MODEL ""
    
	echo "checking ARCH="$ARCH " BUILD_CROSS_COMPILE="$BUILD_CROSS_COMPILE " KERNEL_DEFCONFIG="$KERNEL_DEFCONFIG " BUILD_JOB_NUMBER="$BUILD_JOB_NUMBER

	FUNC_CLEAN_DTB

	make -j$BUILD_JOB_NUMBER ARCH=$ARCH \
		CROSS_COMPILE=$BUILD_CROSS_COMPILE \
		$KERNEL_DEFCONFIG || exit -1

	make -j$BUILD_JOB_NUMBER ARCH=$ARCH \
		CROSS_COMPILE=$BUILD_CROSS_COMPILE || exit -1

	# build dtb file
	FUNC_BUILD_DTIMAGE_TARGET

	# build ramdisk
	FUNC_BUILD_RAMDISK
	
	echo ""
	echo "================================="
	echo "END   : FUNC_BUILD_KERNEL"
	echo "================================="
	echo ""
}

FUNC_BUILD_RAMDISK()
{
	mv $RDIR/arch/$ARCH/boot/Image $RDIR/arch/$ARCH/boot/boot.img-zImage
	# mv $RDIR/arch/$ARCH/boot/dtb.img $RDIR/arch/$ARCH/boot/boot.img-dtb

	RDIR_RELEASE_BIN=$RDIR/release_binary
	# remove old kernel files
	rm -f $RDIR_RELEASE_BIN/split_img/boot.img-zImage
	# rm -f $RDIR_RELEASE_BIN/split_img/boot.img-dtb
	# copy new one
	cp $RDIR/arch/$ARCH/boot/boot.img-zImage $RDIR_RELEASE_BIN/split_img/boot.img-zImage
	# cp $RDIR/arch/$ARCH/boot/boot.img-dtb $RDIR_RELEASE_BIN/split_img/boot.img-dtb
	cd $RDIR_RELEASE_BIN/
	cd ramdisk
	chmod +x ./ramdisk_fix_permissions.sh
	./ramdisk_fix_permissions.sh
	cd ..
	# chmod +x repackimg.sh
	./repackimg.sh

	echo SEANDROIDENFORCE >> image-new.img

	RBIN_OUTDIR=$RDIR/ReleaseBinary
	mkdir -p $RBIN_OUTDIR
	cp image-new.img $RBIN_OUTDIR/$CR_NAME-$CR_VERSION-$CR_DATE.img
}

# MAIN FUNCTION
rm -rf ./build.log
(
    START_TIME=`date +%s`

	FUNC_BUILD_KERNEL
	# FUNC_BUILD_RAMDISK
	# mv $RDIR/arch/$ARCH/boot/Image $RDIR/arch/$ARCH/boot/boot.img-zImage
	# mv $RDIR/arch/$ARCH/boot/dtb.img $RDIR/arch/$ARCH/boot/boot.img-dtb

    END_TIME=`date +%s`
	
#     let "ELAPSED_TIME=$END_TIME-$START_TIME"
    ELAPSED_TIME=$(($END_TIME-$START_TIME))
    echo "Total compile time is $ELAPSED_TIME seconds"
) 2>&1	 | tee -a ./build.log
