; ModuleID = 'decafruntime.c'
source_filename = "decafruntime.c"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.13.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%struct.__Object = type { i8* }
%struct.__String = type { i8*, [1 x i8] }
%struct.__IO = type { i8* }
%struct.__ARRAY = type { i32, [1 x i8] }
%struct.__va_list_tag = type { i32, i32, i8*, i8* }

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@__stdinp = external local_unnamed_addr global %struct.__sFILE*, align 8
@switch.table.doAlloc = private unnamed_addr constant [3 x i32] [i32 2, i32 4, i32 8], align 4

; Function Attrs: norecurse nounwind readnone ssp uwtable
define %struct.__Object* @"Object$$init$"(%struct.__Object* readnone returned) local_unnamed_addr #0 {
  ret %struct.__Object* %0
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define %struct.__String* @"String$$init$"(%struct.__String* readnone returned) local_unnamed_addr #0 {
  ret %struct.__String* %0
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define %struct.__IO* @"IO$$init$"(%struct.__IO* readnone returned) local_unnamed_addr #0 {
  ret %struct.__IO* %0
}

; Function Attrs: nofree nounwind ssp uwtable
define void @"IO$putChar"(i8 signext) local_unnamed_addr #1 {
  %2 = sext i8 %0 to i32
  %3 = tail call i32 @putchar(i32 %2)
  ret void
}

; Function Attrs: nofree nounwind
declare i32 @putchar(i32) local_unnamed_addr #2

; Function Attrs: nofree nounwind ssp uwtable
define void @"IO$putInt"(i32) local_unnamed_addr #1 {
  %2 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 %0)
  ret void
}

; Function Attrs: nofree nounwind
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #2

; Function Attrs: nofree nounwind ssp uwtable
define void @"IO$putString"(%struct.__String*) local_unnamed_addr #1 {
  %2 = getelementptr inbounds %struct.__String, %struct.__String* %0, i64 0, i32 1, i64 0
  %3 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* nonnull %2)
  ret void
}

; Function Attrs: nofree nounwind ssp uwtable
define i32 @"IO$peek"() local_unnamed_addr #1 {
  %1 = load %struct.__sFILE*, %struct.__sFILE** @__stdinp, align 8, !tbaa !3
  %2 = tail call i32 @getc(%struct.__sFILE* %1)
  %3 = load %struct.__sFILE*, %struct.__sFILE** @__stdinp, align 8, !tbaa !3
  %4 = tail call i32 @ungetc(i32 %2, %struct.__sFILE* %3)
  ret i32 %2
}

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #3

; Function Attrs: nofree nounwind
declare i32 @getc(%struct.__sFILE* nocapture) local_unnamed_addr #2

; Function Attrs: nofree nounwind
declare i32 @ungetc(i32, %struct.__sFILE* nocapture) local_unnamed_addr #2

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #3

; Function Attrs: nofree nounwind ssp uwtable
define i32 @"IO$getChar"() local_unnamed_addr #1 {
  %1 = load %struct.__sFILE*, %struct.__sFILE** @__stdinp, align 8, !tbaa !3
  %2 = tail call i32 @fgetc(%struct.__sFILE* %1)
  ret i32 %2
}

; Function Attrs: nofree nounwind
declare i32 @fgetc(%struct.__sFILE* nocapture) local_unnamed_addr #2

; Function Attrs: nounwind ssp uwtable
define i32 @"IO$getInt"() local_unnamed_addr #4 {
  %1 = alloca i32, align 4
  %2 = bitcast i32* %1 to i8*
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %2) #5
  %3 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* nonnull %1)
  %4 = load i32, i32* %1, align 4, !tbaa !7
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %2) #5
  ret i32 %4
}

; Function Attrs: nofree nounwind
declare i32 @scanf(i8* nocapture readonly, ...) local_unnamed_addr #2

; Function Attrs: nounwind ssp uwtable
define %struct.__ARRAY* @"_$ArrayAllocate"(i32, i32, ...) local_unnamed_addr #4 {
  %3 = alloca [1 x %struct.__va_list_tag], align 16
  %4 = bitcast [1 x %struct.__va_list_tag]* %3 to i8*
  call void @llvm.lifetime.start.p0i8(i64 24, i8* nonnull %4) #5
  %5 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  call void @llvm.va_start(i8* nonnull %4)
  %6 = call fastcc %struct.__ARRAY* @doAlloc(i32 %0, i32 %1, i32 0, %struct.__va_list_tag* nonnull %5)
  call void @llvm.lifetime.end.p0i8(i64 24, i8* nonnull %4) #5
  ret %struct.__ARRAY* %6
}

; Function Attrs: nounwind
declare void @llvm.va_start(i8*) #5

; Function Attrs: nofree nounwind ssp uwtable
define internal fastcc %struct.__ARRAY* @doAlloc(i32, i32, i32, %struct.__va_list_tag* nocapture) unnamed_addr #1 {
  %5 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %3, i64 0, i32 0
  %6 = load i32, i32* %5, align 8
  %7 = icmp ult i32 %6, 41
  br i1 %7, label %8, label %14

8:                                                ; preds = %4
  %9 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %3, i64 0, i32 3
  %10 = load i8*, i8** %9, align 8
  %11 = sext i32 %6 to i64
  %12 = getelementptr i8, i8* %10, i64 %11
  %13 = add nuw nsw i32 %6, 8
  store i32 %13, i32* %5, align 8
  br label %18

14:                                               ; preds = %4
  %15 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %3, i64 0, i32 2
  %16 = load i8*, i8** %15, align 8
  %17 = getelementptr i8, i8* %16, i64 8
  store i8* %17, i8** %15, align 8
  br label %18

18:                                               ; preds = %14, %8
  %19 = phi i8* [ %12, %8 ], [ %16, %14 ]
  %20 = bitcast i8* %19 to i32*
  %21 = load i32, i32* %20, align 4
  %22 = add nsw i32 %2, 1
  %23 = icmp ne i32 %22, %1
  %24 = add i32 %0, -1
  %25 = select i1 %23, i32 2, i32 %24
  %26 = icmp ult i32 %25, 3
  br i1 %26, label %27, label %31

27:                                               ; preds = %18
  %28 = sext i32 %25 to i64
  %29 = getelementptr inbounds [3 x i32], [3 x i32]* @switch.table.doAlloc, i64 0, i64 %28
  %30 = load i32, i32* %29, align 4
  br label %31

31:                                               ; preds = %27, %18
  %32 = phi i32 [ 1, %18 ], [ %30, %27 ]
  %33 = mul nsw i32 %32, %21
  %34 = add i32 %33, 4
  %35 = sext i32 %34 to i64
  %36 = tail call i8* @malloc(i64 %35) #8
  %37 = bitcast i8* %36 to %struct.__ARRAY*
  %38 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %36, i1 false, i1 true, i1 false)
  %39 = tail call i8* @__memset_chk(i8* %36, i32 0, i64 %35, i64 %38) #5
  %40 = bitcast i8* %36 to i32*
  store i32 %21, i32* %40, align 4, !tbaa !9
  %41 = icmp sgt i32 %21, 0
  %42 = and i1 %23, %41
  br i1 %42, label %43, label %53

43:                                               ; preds = %31
  %44 = getelementptr inbounds i8, i8* %36, i64 4
  %45 = bitcast i8* %44 to %struct.__ARRAY**
  br label %46

46:                                               ; preds = %46, %43
  %47 = phi %struct.__ARRAY** [ %50, %46 ], [ %45, %43 ]
  %48 = phi i32 [ %51, %46 ], [ 0, %43 ]
  %49 = tail call fastcc %struct.__ARRAY* @doAlloc(i32 %0, i32 %1, i32 %22, %struct.__va_list_tag* %3)
  %50 = getelementptr inbounds %struct.__ARRAY*, %struct.__ARRAY** %47, i64 1
  store %struct.__ARRAY* %49, %struct.__ARRAY** %47, align 8, !tbaa !3
  %51 = add nuw nsw i32 %48, 1
  %52 = icmp eq i32 %51, %21
  br i1 %52, label %53, label %46

53:                                               ; preds = %46, %31
  ret %struct.__ARRAY* %37
}

; Function Attrs: nofree nounwind ssp uwtable
define i32 @main(i32, i8** nocapture readnone) local_unnamed_addr #1 {
  %3 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 123) #5
  %4 = tail call i32 @putchar(i32 10) #5
  ret i32 0
}

; Function Attrs: nofree nounwind allocsize(0)
declare noalias i8* @malloc(i64) local_unnamed_addr #6

; Function Attrs: nofree nounwind
declare i8* @__memset_chk(i8*, i32, i64, i64) local_unnamed_addr #2

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.objectsize.i64.p0i8(i8*, i1 immarg, i1 immarg, i1 immarg) #7

attributes #0 = { norecurse nounwind readnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nofree nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nofree nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { argmemonly nounwind }
attributes #4 = { nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind }
attributes #6 = { nofree nounwind allocsize(0) "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nounwind readnone speculatable }
attributes #8 = { allocsize(0) }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 9.0.0 (tags/RELEASE_900/final)"}
!3 = !{!4, !4, i64 0}
!4 = !{!"any pointer", !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C/C++ TBAA"}
!7 = !{!8, !8, i64 0}
!8 = !{!"int", !5, i64 0}
!9 = !{!10, !8, i64 0}
!10 = !{!"__ARRAY", !8, i64 0, !5, i64 4}
